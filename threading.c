#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun1(void *vargp)
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
    	sleep(1);
    	printf("Hello from Thread 1\n");
    }
    return NULL;
}

void *myThreadFun2(void *vargp)
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
    	sleep(4);
    	printf("Hello from Thread 2\n");
    }
    return NULL;
}

int main()
{
    pthread_t thread_id1, thread_id2;

    printf("Before Thread\n");
    pthread_create(&thread_id1, NULL, myThreadFun1, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun2, NULL);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("After Thread\n");

    return 0;
}
