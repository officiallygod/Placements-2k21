#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
long long int a = 0;

void threadFunc()
{
    int i;
    long int localA = 0;

    for (i = 1; i < 5000; i++)
    {
        localA = localA + i;
    }

    pthread_mutex_lock(&lock);
    a = a + localA;
    pthread_mutex_unlock(&lock); 
}

void threadFunc2()
{
    int i;
    long int localA = 0;

    for (i = 5000; i <= 10000; i++)
    {
        localA = localA + i;
    }

    pthread_mutex_lock(&lock);
    a = a + localA;
    pthread_mutex_unlock(&lock);
}

int main(int argc, char **argv)
{
    pthread_t one, two;

    pthread_mutex_init(&lock, NULL);
    pthread_create(&one, NULL, (void *)&threadFunc, NULL);
    pthread_create(&two, NULL, (void *)&threadFunc2, NULL);

    pthread_join(one, NULL);
    pthread_join(two, NULL);

    pthread_mutex_destroy(&lock);

    printf("%ld\n", a);

    return 0;
}