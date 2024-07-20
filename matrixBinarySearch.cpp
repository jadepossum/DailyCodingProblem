#include<iostream>
#include<vector>
using namespace std;

bool is_present(vector<vector<int>>& arr,int r,int c,int req_num){
    int low = 0;
    int high = r-1;
    int mid = 0;
    while(high>=low){
        mid = (low+high)/2;
        if(arr[mid][0]<=req_num&&arr[mid][c-1]>=req_num){
            int curr_low = 0;
            int curr_high = c-1;
            int curr_mid;
            while(curr_high>=curr_low){
                curr_mid = (curr_high+curr_low)/2;
                if(arr[mid][curr_mid]==req_num){
                    cout<<"The required number '"<<req_num<<"'"<<" is present at index ("<<mid<<","<<curr_mid<<")"<<endl;
                    return true;
                    }
                else if(arr[mid][curr_mid]<req_num) curr_low = curr_mid+1;
                else if(arr[mid][curr_mid]>req_num) curr_high = curr_mid-1;
            }
            if(curr_high<curr_low){ 
                cout<<"The required number '"<<req_num<<"'"<<" is not present in the matrix"<<endl;
                return false;
            }
        }
        else if(arr[mid][0]>req_num) high = mid-1;
        else if(arr[mid][c-1]<req_num) low = mid + 1;
    }
    cout<<"The required number '"<<req_num<<"'"<<" is not present in the matrix"<<endl;
    return false;
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 8;
    int num_of_rows = mat.size();
    int num_of_cols = mat[0].size();
    
    cout<<"The Given Matrix is :"<<endl;
    for(auto arr:mat){
        for(auto elem:arr) cout<<" "<<elem;
        cout<<endl;
    }

    bool ans = is_present(mat,num_of_rows,num_of_cols,k);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}