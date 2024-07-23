#include<iostream>
using namespace std;
int function_one(int n){
    if(n==1||n==2){
        return n;
    }
    return function_one(n-1) + function_one(n-2);
}
int function_two(int* arr,int n){
    if(n==1||n==2) return n;
    if(arr[n-1]==0){
        int r =  function_two(arr,n-1)+function_two(arr,n-2);
        arr[n-1] = r;
        return r;
    }
    return arr[n-1];
}
int function_three(int curr,int x,int y,int n){
    if(curr==1){
        x = 1;
        y = 1;
    }
    if(curr==n){
        return y;
    }
    return function_three(curr+1,y,x+y,n);
}
int function_four(int n){
    if(n==1||n==2) return n;
    int x = 1;
    int y = 2;
    int temp = 0;
    for(int j = 3;j<=n;j++){
        temp = y+x;
        x = y;
        y = temp;
    }
    return y;
}
int main(){
    int stair_count = 3;
    int lookup_table[stair_count] = {0};
    cout<<"(Function one) possible ways to climb to the top is :"<<function_one(stair_count)<<endl;
    cout<<"(Function Two) possible ways to climb to the top is :"<<function_two(lookup_table,stair_count)<<endl;
    cout<<"(Function Three) possible ways to climb to the top is :"<<function_three(1,0,1,stair_count)<<endl;
    cout<<"(Function Four) possible ways to climb to the top is :"<<function_four(stair_count)<<endl;
    return 0;
}