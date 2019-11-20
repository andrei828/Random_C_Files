#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/errno.h>

#define MAX_RESOURCES 5
#define NUM_OF_THREADS 5

pthread_mutex_t mtx;
int count = 0, available_resources = MAX_RESOURCES;

int increase_count(int count);
int decrease_count(int count);

void * exec_threads(void * null_params) {
	int num_of_needed_resources = rand() % 2 + 1;


	pthread_mutex_lock(&mtx);
	if (decrease_count(num_of_needed_resources) < 0) {
		printf("There are not enough resources available\n");

	} else {
	printf("Got %d resources %d remaining\n", 
		num_of_needed_resources, available_resources);
	}
	
	pthread_mutex_unlock(&mtx);
	
	
	pthread_mutex_lock(&mtx);

	increase_count(num_of_needed_resources);
	printf("Released %d resources %d remaining\n", 
			num_of_needed_resources, available_resources);
	
	pthread_mutex_unlock(&mtx);
	return NULL;
}






int main() {
	srand(time(NULL));

	pthread_t * threads = malloc(NUM_OF_THREADS * sizeof(pthread_t));

	if (pthread_mutex_init(&mtx, NULL)) {
		perror(NULL);
		return errno;
	}
	printf("MAX_RESOURCES=%d\n", MAX_RESOURCES);
	for (int i = 0; i < NUM_OF_THREADS; i++) {
		if (pthread_create(&threads[i], NULL, exec_threads, NULL)) {
			perror(NULL);
			return errno;
		}
	}

	for (int i = 0; i < NUM_OF_THREADS; i++) {
		if (pthread_join(threads[i], NULL)) {
			perror(NULL);
			return errno;
		}
	}

}

int increase_count(int count) {
	available_resources += count;
	return 0;
}

int decrease_count(int count) {
	if (available_resources < count)
		return -1;
	else
		available_resources -= count;
	return 0;
}