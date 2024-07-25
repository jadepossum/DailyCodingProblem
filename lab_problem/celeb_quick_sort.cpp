#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sorting_by_arjun(vector<int>& arr,int low,int high){
    if(low>=high) return;
    int i = low;
    int j = low;
    while(j<high){
        if(arr[j]<arr[high]){
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i],arr[high]);
    sorting_by_arjun(arr,low,i-1);
    sorting_by_arjun(arr,i+1,high);
    return;
}
void sorting_by_priya(vector<int>& arr,int low,int high){
    if(low>=high) return;
    int i = high;
    int j = high;
    while(j>low){
        if(arr[j]>arr[low]){
            swap(arr[i],arr[j]);
            i--;
        }
        j--;
    }
    swap(arr[i],arr[low]);
    sorting_by_priya(arr,low,i-1);
    sorting_by_priya(arr,i+1,high);
    return;
}
int main(){
    //sorting by arjun
    vector<int> guest_list1={4, 1, 3, 9,15,12,10,7};
    cout<<"The given guest_list1 is : ";
    for(auto guest:guest_list1){
        cout<<" "<<guest;
    }
    sorting_by_arjun(guest_list1,0,guest_list1.size()-1);
    cout<<"\nThe sorted guest_list1 (by arjun) is : ";
    for(auto guest:guest_list1){
        cout<<" "<<guest;
    }

    //sorting by priya
    vector<int> guest_list2={6, 2, 4, 8,14,11,16,7};
    cout<<"\n\nThe given guest_list2 is : ";
    for(auto guest:guest_list2){
        cout<<" "<<guest;
    }
    sorting_by_priya(guest_list2,0,guest_list2.size()-1);
    cout<<"\nThe sorted guest_list2 (by priya) is : ";
    for(auto guest:guest_list2){
        cout<<" "<<guest;
    }
    return 0;
}