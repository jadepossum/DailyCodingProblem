#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n = 6;
    vector<vector<int>> Edges = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,5},{4,5},{2,3}};
    vector<vector<int>> adj_mat;
    vector<int> indeg(n,0);
    vector<int> sorted_elems;
    queue<int> tempq;

    for(int i=0;i<n;i++){
        adj_mat.push_back(indeg);
    }
    for(auto elem:Edges) 
        adj_mat[elem[0]][elem[1]] = 1;

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j = 0;j<n;j++){
            if(adj_mat[j][j]==1) count++;
        }
        indeg[i]=count;
    }
    int x = 0;
    while(x<10&&sorted_elems.size()!=n){
            for(int i = 0;i<n;i++){
                if(indeg[i]==0){
                    tempq.push(i);
                }
            }
            while(!tempq.empty()){
                for(int i = 0;i<n;i++){
                    if(adj_mat[tempq.front()][i]==1){
                        indeg[i]--;
                    }
                }
                sorted_elems.push_back(tempq.front());
                tempq.pop();
            }
            x++;
    }
    cout<<"The sorted elements (using BFS) are : [ ";
    for(auto elem:sorted_elems){
        cout<<elem<<" ";
    }
    cout<<"]\n";
    return 0;
}