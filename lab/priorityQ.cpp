#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int priority = 0;
    int data = 0;
}a;

class Heap{
    vector<Node> arr = {a};
    int capacity = 0;
    public:
    void insert(int val,int priority){
        Node b;
        b.data = val;
        b.priority = priority;
        arr.push_back(b);
        // cout<<"inserted element : "<<arr[capacity+1].data<<endl;
        int n = arr.size()-1;
        while(n>1&&arr[n].priority>arr[n/2].priority){
             swap(arr[n],arr[n/2]);
             n/=2;
        }
        return;
    }
    void deleteMax(){
        if(arr.size()==1){
            cout<<"Priority Queue is empty"<<endl;
            return;
        }
        if(arr.size()==2){
            arr.pop_back();
            return;
        }
        swap(arr[1],arr[arr.size()-1]);
        arr.pop_back();
        capacity--;
        build_heap();
    }
    void build_heap(int ind=1){
        int largest = ind;
        int n = arr.size()-1;
        if(2*ind<=n&&arr[largest].priority<arr[2*ind].priority) largest = 2*ind;
        if((2*ind+1)<=n&&arr[largest].priority<arr[2*ind+1].priority) largest = 2*ind+1;
        if(!(largest==ind)){
            swap(arr[ind],arr[largest]);
            build_heap(largest);
        }
    }
    void printHeap(){
        if(arr.size()==1){ 
            cout<<"priorityQ is Empty..\n";
            return;
        }
        cout<<"The elements in the priority Queue are :\n";
        for(int i = 1;i<arr.size();i++){
            cout<<"  Data: "<<arr[i].data<<" ,";
            cout<<"  Priority :"<<arr[i].priority<<"\n";
        }
    }
};

int main(){
    Heap priorityQ;
    int option = -1;
    int data = 0;
    int priority = 0;
    do{
        cout<<"\n\nMenu :\n";
        cout<<"1. Insert an element :\n";
        cout<<"2. Delete the highest element of the priority queue :\n";
        cout<<"3. print the elements of the priority queue :\n";
        cout<<"4. Exit :\n";
        cout<<"enter your choice :";
        cin>>option;
        switch (option){
            case 1:
                cout<<"Enter data :";
                cin>>data;
                cout<<"Enter priority :";
                cin>>priority;
                priorityQ.insert(data,priority);
                break;
            case 2:
                priorityQ.deleteMax();
                break;
            case 3:
                priorityQ.printHeap();
                break;
            default:
                option = 4;
                cout<<"Exiting...";
                break;
        }
    }while(option!=4);
    return 0;
}