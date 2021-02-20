#include <stdio.h>

#include "sched.h"
#include "thread.h"
#include "xtimer.h"

#define NUMTHREADS 5

char thread_stack[NUMTHREADS][THREAD_STACKSIZE_MAIN];
int thread_stack_index = 0;

void * thread_controller (void *arg) {
  (void) arg;

  while (sched_active_thread->service_time < sched_active_thread->max_service_time) {
    // Wait
  }

  return NULL;
}

// Creates the thread with a service time
void tester_thread_create (char thread_name[], uint64_t thread_lifetime) {
  kernel_pid_t pid = thread_create(thread_stack[thread_stack_index], sizeof(thread_stack[thread_stack_index]), 1, 0, &thread_controller, NULL, thread_name);
  sched_threads[pid]->max_service_time = thread_lifetime;
  thread_stack_index++;
}

int main(void)
{
  tester_thread_create("A", 3000000);
  tester_thread_create("B", 6000000);
  tester_thread_create("C", 4000000);
  tester_thread_create("D", 5000000);
  tester_thread_create("E", 2000000);

  return 0;
}
