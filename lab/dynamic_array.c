#include<stdio.h>
#include<stdlib.h>
int main(){
  //assign the size required
  int n = 0;
  int newdynsize=0;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  //assign dynamic memory
  int* d_mem = (int*)malloc(n*sizeof(int));
  printf("enter the %d elements : ",n);
  int iter = 0;
  while(iter<n){
    scanf("%d",d_mem+iter);
    iter++;
  }
  
  printf("The elements in the dynamic array are : [ ");
  for(iter = 0;iter<n-1;iter++){
    printf("%d, ",d_mem[iter]);
  }
  printf("%d ]\n",d_mem[n-1]);
  
  
  char resize;
  printf("Do you want to resize the array? (y/n) :\n");
  scanf("%c",&resize);
  scanf("%c",&resize);
  
  if(resize=='y'){
      printf("Enter the new size of the array :");
      scanf("%d",&newdynsize);
      d_mem = realloc(d_mem,newdynsize);
      if(newdynsize>n){
          printf("Enter the new %d elements :",newdynsize-n);
          int i = 0;
          for(i =n;i<newdynsize;i++){
            scanf("%d",d_mem+i);
            i++;
          }
          n=newdynsize;
          printf("The elements in the dynamic array are : [ ");
            for(iter = 0;iter<n-1;iter++){
                printf("%d, ",d_mem[iter]);
            }
            printf("%d ]\n",d_mem[n-1]);
      }
  }
  
  printf("Reversing the dynamic array : [ ");
  for(iter = 0;iter<newdynsize/2;iter++){
    int temp = d_mem[iter];
    d_mem[iter] = d_mem[n-iter-1];
    d_mem[n- iter -1] = temp;
  }
 for(iter = 0;iter<n-1;iter++){
    printf("%d, ",d_mem[iter]);
  }
  printf("%d ]\n",d_mem[n-1]);
  
  printf("\nFreeing memory...");
  free(d_mem);
  printf("memory freed");
  return 0;
}