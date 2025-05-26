#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
bool f = false;
pthread_mutex_t lock = PTHREAD_COND_INITIALIZER;
void* say_hello(void* arg) {
    while(!f) {
        printf("Hello from thread!\n");
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, say_hello, NULL);
    getchar(); // Wait for user input to stop the thread
    f = true; // Set the flag to stop the thread
    pthread_join(thread, NULL); // Wait for thread to finish
    return 0;
}
