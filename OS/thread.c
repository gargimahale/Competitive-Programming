#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"

// A multithreaded program - Threads do no execute atomically leading
// to different output for higher values of N

volatile int cnt = 0;
int loops;

void *worker(void *arg){
    int i;
    for(i = 0; i < loops; i++){
        ++cnt;
    }
    return NULL;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr,"usage: cpu <string>\n");
        exit(1);
    }
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial Value: %d\n", cnt);
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final Vlaue: %d\n", cnt);
    return 0;
}