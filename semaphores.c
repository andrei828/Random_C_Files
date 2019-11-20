#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/errno.h>

#define NTHRS 5
#define NUM_OF_THREADS 5

sem_t sem;
int S = 0;
pthread_mutex_t mtx;

void barrier_point() {
	
	pthread_mutex_lock(&mtx);
	S++;
	pthread_mutex_unlock(&mtx);

	if (S == NTHRS && sem_post(&sem)) {
		perror(NULL);
	}

	if (sem_wait(&sem)) {
		perror(NULL);
	}

	if (sem_post(&sem)) {
		perror(NULL);
	}

}

void * exec_threads(void * v) {

	int * tid = (int *)v;

	printf("%d reached the barrier\n", *tid);
	barrier_point();
	printf("%d passed the barrier\n", *tid);
	//free(tid);
	return NULL;
}





int main() {
	srand(time(NULL));

	pthread_t * threads = malloc(NUM_OF_THREADS * sizeof(pthread_t));

	if (sem_init(&sem, 0, S)) {
		perror(NULL);
		return errno;
	}

	if (pthread_mutex_init(&mtx, NULL)) {
		perror(NULL);
		return errno;
	}

	int * tids = malloc(NTHRS * sizeof(int));
	if (!tids) {
		perror(NULL);
		return errno;
	}

	printf("NTHRS=%d\n", NTHRS);
	for (int i = 0; i < NTHRS; i++) {
		tids[i] = i + 1;
		if (pthread_create(&threads[i], NULL, exec_threads, &tids[i])) {
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
