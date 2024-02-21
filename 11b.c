#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myNewThread(void *vargp) {
    printf("Hello world\n");
    return NULL;
}

void *myThreadFun(void *vargp) {
    int *myid = (int *)vargp;
    printf("%lu %d ", pthread_self(), *myid);
    pthread_t nid;
    
    if (pthread_equal(pthread_self(), *((pthread_t *)vargp))) {
        printf("main thread encountered\n");
        int i, j;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                pthread_create(&nid, NULL, myNewThread, NULL);
                pthread_join(nid, NULL);
            }
        }
    }
    return NULL;
}

int main() {
    int i;
    pthread_t tid;
    for (i = 0; i < 2; i++) {
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
        pthread_join(tid, NULL);
    }
    pthread_exit(NULL);
    return 0;
}

