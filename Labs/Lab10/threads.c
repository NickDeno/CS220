#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_var = 0;

void *worker_function(void *payload){
  (*(int *)payload)++;
  printf("In thread %d\n", * (int *) payload);
  global_var++;
  printf("global_var value: %d\n", global_var);
}

#define NUM_THREADS 3

int main() {
  pthread_t threads [NUM_THREADS];
  int i;
  int * payload = (int *)malloc(sizeof(int));

  // declare payload
  *payload = 800;
  int* x = (int *)malloc(sizeof(int));
  for (i = 0; i < NUM_THREADS; i++){
    pthread_create(&threads[i], NULL, worker_function, (void *)x);
  }
  *x = 5;

  printf("In main thread\n");

  for(i = 0; i < NUM_THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  printf("Exiting main thread\n");
  pthread_exit(NULL);
  return 0;
}
