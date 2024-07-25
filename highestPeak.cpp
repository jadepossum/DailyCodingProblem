#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> mountain_range={1,2,20,4,5,6,7,3,2};
    vector<int> ans;
    for(int i=1;i<mountain_range.size()-1;i++){
        if(mountain_range[i]>mountain_range[i-1]&&mountain_range[i]>mountain_range[i+1]){
            ans.push_back(i);
        }
    }
    cout<<"The peaks are at :";
    for(auto peak:ans){
        cout<<" "<<peak;
    }
    return 0;
}