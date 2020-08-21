#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
pthread_mutexattr_t              mutex_attr;
pthread_condattr_t               cond_attr;


int main() {

    printf("\nHello!!!\n");

    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&mutex, &mutex_attr);

    pthread_condattr_init(&cond_attr);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&condition_var, &cond_attr);

    pthread_cond_wait(&condition_var, &mutex);
    printf("\n[%s]\n", __FILE__);

    printf("\nExit...\n");
    return 1;
}
