#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFSTraversal(int n,vector<vector<int>>& arr){
    int len = arr.size();
    if(len==0){
        cout<<"\nThere is no graph to Traverse";
    }
    if(len==1){
        cout<<"\nBFS Traversal starting from vertex "<<n<<" is : ["<<arr[0][0]<<"]\n";
    }
    vector<int> b(arr.size(),0);
    b[n] = 1;
    queue<int> visiting;
    visiting.push(n);

    cout<<"\nBFS Traversal starting from vertex "<<n<<" is :\n[ "<<n<<" ";
    while (!visiting.empty())
    {
        for(int i = 0;i<len;i++){
            if(arr[visiting.front()][i]==1&&b[i]==0){
                cout<<i<<" ";
                visiting.push(i);
                b[i]=1;
            }
        }
        visiting.pop();
    }
    cout<<"]";
    return;
}
int main(){
    int n = 5;
    int vertex = 0;
    vector<vector<int>> edges = {{0,1},{0,4},{1,2},{1,3},{1,4},{2,3},{3,4}};
    vector<vector<int>> adj_mat;
    vector<int> a(n);
    for(int i =0;i<n;i++){
        adj_mat.push_back(a);
    }
    for(auto edge:edges){
        adj_mat[edge[0]][edge[1]] = 1;
    }
    cout<<"The Adjacency Matrix is :\n";
    for(auto arr:adj_mat){
        for(auto elem : arr){
            cout<<" "<<elem;
        }
        cout<<"\n";
    }
    BFSTraversal(vertex,adj_mat);
    return 0;
}