#include <pthread.h>
#include <stdio.h>

void* func1
{
    printf("This is thread function");
}

void* func2
{
    int a=100, b=200;
    pthread
}

int main()
{
    
    pthread_t thread1, thread2;
    pthread_create(thread1,NULL,func1,NULL);
    pthread_create(thread2,NULL,func2,NULL);
}