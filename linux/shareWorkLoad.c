#include<stdio.h>
#include<pthread.h>

int num_arr[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int part_sum[4] = {0,0,0,0};

void* my_partial_sum(void* my_end){
  int *end = (int *)my_end;
  int i = 0;
  for(i = *end - 4;i<*end;i++)
      part_sum[(*end)/4 - 1]+=num_arr[i];
  printf("The partial sum of thread_%d is : %d\n",(*end)/4 - 1,part_sum[(*end)/4 - 1]);
  return NULL;
}

int main(){
  pthread_t thread_arr[4];
  int end_ind[4];
  
  for(int i = 0;i<4;i++){
    end_ind[i] = (i+1)*4;
    pthread_create(&thread_arr[i],NULL,my_partial_sum,&end_ind[i]);
  }
  for(int i =0;i<4;i++){
    pthread_join(thread_arr[i],NULL);
  }
  
  int sum = 0;
  for(int i = 0;i<4;i++) sum+=part_sum[i];
  
  printf("The total sum is : %d\n",sum);
  return 0;
}