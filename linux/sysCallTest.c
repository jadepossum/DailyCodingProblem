#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
#include<stdlib.h>
int main(){
  pid_t p = fork();
  if(p<0){
    perror("fork fail");
    exit(1);
    }
  if(p>0){
    printf("In parent process\n");
    printf("new process is created with pid : %d\n",p);
    sleep(5);
    printf("parent process terminated\n");
    exit(0);
  }
  else{
    printf("In Child process\n");
    printf("Current Parent at the time of creation is : %d\n",getppid());
    int i = 1;
    while(i<7){
      printf("At '%ds' the parent pid is :%d\n",i,getppid());
      i++;
      sleep(1);
    }
    printf("After 6s the current parent is : %d\n",getppid());
  }
  return 0;
}