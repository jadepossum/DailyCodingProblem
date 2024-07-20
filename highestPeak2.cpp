#include<iostream>
#include<vector>
using namespace std;

int find_peak(vector<int> arr,int low,int high){
    if(high<low) return -1;
    int mid = (low+high)/2;
    if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
            return mid;
    }
    else if(arr[mid]<arr[mid-1]){
        return find_peak(arr,low,mid-1);
    }
    else if(arr[mid]<arr[mid + 1]){
        return find_peak(arr,mid+1,high);
    }
    return 0;
}

int main(){
    vector<int> mountain_range={1,2,20,4,5,4,6,7,3,2};
    vector<int> ans;

    //brute force solution
    for(int i=1;i<mountain_range.size()-1;i++){
        if(mountain_range[i]>mountain_range[i-1]&&mountain_range[i]>mountain_range[i+1]){
            ans.push_back(i);
        }
    }
    if(ans.size()==0) cout<<"There is no peak";
    else{
        cout<<"(BRUTE FORCE SOLUTION)The peaks are at :";
        for(auto peak:ans){
            cout<<" "<<peak;
        }
        cout<<endl;
    }
    //divide and conquer solution
    int low = 0;
    int high = mountain_range.size()-1;
    cout<<"(OPTMIZED SOLUTION)The peak is at :"<<find_peak(mountain_range,low,high);
    return 0;
}