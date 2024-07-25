// 2)Given integers M and N, write a program that counts how many positive integer pairs (a, b) satisfy the following conditions:

// a + b = M
// a XOR b = N

// solution
#include<stdio.h>
int main(){
    int a,b;
    int count = 0;
    int M = 10;
    int N = 3;

    //solution
    for(int a = 0;a<=M/2;a++){
        int b = M - a;
        if(a^b==N) count++;
    }
return 0;
}