#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap{
    vector<int> arr = {0};
    int size = 0;
    int capacity = 0;
    public:
    void set_size(int n){
        this->size = n;
    }
    Heap(int n){
        this->size = n;
    }
    void max_heapify(int ind){
        if(ind<=1) return;
        int n = ind/2;
        if(arr[n]<arr[ind]){
            swap(arr[ind],arr[n]);
            max_heapify(n);
        }
    }
    void insert(int val){
        if(size==0){
            cout<<"set the size of the Heap (heap.set_size(val)) before using\n";
            return;
        }
        if(capacity==size){
            cout<<"The heap is full, cannot insert the val :"<<val<<endl;
            return;
        }
        arr.push_back(val);
        cout<<"inserted element : "<<arr[capacity+1]<<endl;
        if(capacity==0){
            capacity++;
            return;
        }
        int n = ++capacity;
        // cout<<"n is :"<<n<<endl;
        int i  = n/2;
        int largest = i;
        if((2*i)<=capacity&&arr[largest]<arr[(2*i)]){
            // cout<<"left is bigger"<<endl;
             largest = 2*i;
        }
        if((2*i+1)<=capacity&&arr[largest]<arr[(2*i)+1]) 
        {
            // cout<<"right is bigger"<<endl;
            largest = (2*i )+1;
        }
        // cout<<largest<<" ::: "<<i<<" "<<!(largest==i)<<endl;
        if(!(largest==i)){
            // cout<<"swapping"<<endl;
            swap(arr[i],arr[largest]);
            max_heapify(i);
        }
        return;
    }
    void deleteMax(){
        if(capacity==0){
            cout<<"heap is empty"<<endl;
            return;
        }
        if(capacity==1){
            arr.pop_back();
            capacity--;
            return;
        }
        swap(arr[1],arr[capacity]);
        arr.pop_back();
        capacity--;
        build_heap();
    }
    void build_heap(int ind=1){
        int largest = ind;
        if(2*ind<=capacity&&arr[largest]<arr[2*ind]) largest = 2*ind;
        if((2*ind+1)<=capacity&&arr[largest]<arr[2*ind+1]) largest = 2*ind+1;
        if(!(largest==ind)){
         swap(arr[ind],arr[largest]);
         build_heap(largest);
        }
    }
    void printHeap(){
        cout<<"The maxHeap in array format is :[ ";
        for(int i = 1;i<capacity+1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]";
    }
};

int main(){
    Heap newheap(5);
    newheap.insert(5);
    newheap.insert(6);
    newheap.insert(7);
    newheap.insert(8);
    newheap.printHeap();
    newheap.deleteMax();
    newheap.printHeap();
    return 0;
}