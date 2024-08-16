#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
using namespace std;

int main(){
    int nvertices = 4;
    vector<vector<int>> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    make_heap(edges.begin(),edges.end(),[&](vector<int> a,vector<int> b){return a[2]>b[2];});
    vector<vector<int>> mst;

    int edgecount = edges.size();
    set<int> visited;
    visited.insert(edges.front()[0]);
    int nedges = 0;
    
    cout<<"edges :"<<endl;
    for(auto elem:edges){
        cout<<elem[2]<<endl;
    }

    while(nedges<10&&mst.size()<nvertices-1){
        vector<vector<int>> temp;
        pop_heap(edges.begin(),edges.end());
        if(!edges.empty()){
            if(visited.find(edges.back()[0])!=visited.end()||visited.find(edges.back()[1])!=visited.end()){
                cout<<"edge back:"<<edges.back()[2]<<endl;
                visited.insert(edges.back()[0]);
                visited.insert(edges.back()[1]);
                mst.push_back(edges.back());
                cout<<"adding to mst :"<<mst.back()[0]<<mst.back()[1]<<mst.back()[2]<<endl;
            }
            edges.pop_back();
        }
        nedges++;
    }

    cout<<"edges :"<<endl;
    for(auto elem:edges){
        cout<<elem[2]<<endl;
    }

    int tot_weight = 0;
    cout<<"edges in mst :"<<endl;
    for(auto elem:mst){
        tot_weight+=elem[2];
        cout<<elem[2]<<endl;
    }

    cout<<"total weight of mst is :"<<tot_weight<<endl;
    return 0;
}
