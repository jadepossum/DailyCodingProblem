#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(vector<vector<int>>& arr,vector<int>& vis,stack<int>& stk,int node){
    vis[node] = 1;
    for(int i =0 ;i<arr.size();i++){
        if(arr[node][i]==1&&vis[i]==0){
            DFS(arr,vis,stk,i);
        }
    }
    stk.push(node);
}
int main(){
    int n = 6;
    vector<vector<int>> Edges = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,5},{4,5},{2,3}};
    vector<vector<int>> adj_mat;
    vector<int> visited(n,0);
    stack<int> temp;

    for(int i=0;i<n;i++){
        adj_mat.push_back(visited);
    }
    for(auto elem:Edges) 
        adj_mat[elem[0]][elem[1]] = 1;

    int z = 0;
    while(z==0){
            z=1;
            for(int i = 0;i<n;i++){
                if(visited[i]==0){
                    z = 0;
                    DFS(adj_mat,visited,temp,i);
                }
            }
            
    }

    cout<<"The sorted elements (using DFS) are : [ ";
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }

    cout<<"]\n";
    return 0;
}