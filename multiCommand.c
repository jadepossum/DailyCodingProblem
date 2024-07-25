
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

char* command_one[] = {"echo","This is a test of echo command",NULL};
char* command_two[] = {"mkdir","new_directory",NULL};
char* command_three[] = {"ls",NULL};
char* command_four[] = {"rm","bogus_file",NULL};

void exec_sys_command(void ind){
  int* index = (int*) ind;
  pid_t pid = fork();
  int status;
  if(pid==0){
    if(*index==0) execvp(command_one[0],command_one);
    if(*index==1) execvp(command_two[0],command_two);
    if(*index==2) execvp(command_three[0],command_three);
    if(*index==3) execvp(command_four[0],command_four);
  }
  else if(pid>0){
    wait(&status);
  }
  return NULL;
}
int main(){
  pthread_t command_exec_threads[4];
  int ind[4] = {0,1,2,3};
  for(int i=0;i<5;i++){
    pthread_create(&command_exec_threads[i],NULL,exec_sys_command,&ind[i]);
  }
  for(int i=0;i<5;i++){
    pthread_join(command_exec_threads[i],NULL);
  }
  printf("Main() Exiting....");
  return 0;
}
