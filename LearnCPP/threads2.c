#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int data_ready = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* consumer(void* arg) {
    pthread_mutex_lock(&lock);
    
    while (!data_ready) {  // check condition
        printf("Consumer: waiting for data...\n");
        pthread_cond_wait(&cond, &lock); // releases lock & sleeps
    }

    // When signaled, lock is reacquired
    printf("Consumer: received data!\n");

    pthread_mutex_unlock(&lock);
    return NULL;
}

void* producer(void* arg) {
    sleep(2);  // simulate work
    pthread_mutex_lock(&lock);

    data_ready = 1;
    printf("Producer: data ready, signaling...\n");

    pthread_cond_signal(&cond);  // wake one waiting thread

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t prod, cons;
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_create(&prod, NULL, producer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}
