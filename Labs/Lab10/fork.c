#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 1;
  pid_t pid;
  pid = fork();

  if (pid == 0) {
    x++;
    printf("In child\n");
    getppid();
    printf("Pid: %d\n", pid);
  } else {
    x--;
    sleep(1);
    printf("In parent\n");
    getppid();
    printf("Parent Process ID: %d\n", pid);
  }
  return(0);
}
