#include <pthread.h>
#include <stdio.h>

long rand = 0;
pthread_mutex_t mutex;

void *counter(void* arg){
    long n = *(long *)arg;
    for (long i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        rand++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    long n1 = 1000000;
    long n2 = 1000000;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, counter, &n1);
    pthread_create(&thread2, NULL, counter, &n2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&mutex);
    printf("expected: %d, got: %ld\n", 20000000, rand);
}