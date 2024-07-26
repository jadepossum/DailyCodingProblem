#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[]){
	int n = 1;
	while(n<argc){ 
	   int z = strlen(argv[n]);
	   char str[z];
	   strcpy(str,argv[n]);
	   for(int i = 0;i<z-1;i++){
	     if(str[i]>='A'&&str[i]<='Z'){
	     	str[i] = ('a' + (str[i] - 'A'));
	     }
	     else{
		str[i] = ('A' + (str[i] - 'a'));
	     }
	   }
	   n++;
	   printf("%s ",str);
	}
	printf("\n");
return 0;
}

