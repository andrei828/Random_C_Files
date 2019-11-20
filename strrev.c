#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/errno.h>

int test = 0;

void * strrev(void * v) {
	
	char * str = (char *)v;

	int i = 0, counter = strlen(str);

	for (int i = 0; i < counter / 2; i++) {
		int tmp = str[i];
		str[i] = str[counter - i - 1];
		str[counter - i - 1] = tmp;
	}
	
	return str;
}

int main(int argc, char ** argv) {

	pthread_t thread;

	if (pthread_create(&thread, NULL, strrev, argv[1])) {
		perror(NULL);
		return errno;
	}

	char * res;
	if (pthread_join(thread, (void *) &res)) {
		perror(NULL);
		return errno;
	} else {
		printf("%s\n", res);
	}
}
