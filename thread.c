#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void printids(const char * s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (Ox%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned 		long)tid);
}

void * thd_fn(void * arg)
{
	printids("new thread:");
	return ((void *)0);
}

int main()
{
	pthread_t id = 0;
	
	id = pthread_create(&id, NULL, thd_fn, NULL);

	if (id != 0)
	{
		printf("create thread failed!");
	 	goto l_fail;
	}
	sleep(2);

l_fail:
	return 0;
}
