#include<iostream>
#include<vector>
using namespace std;

class customNode{
    public:
        int data = 0;
        customNode* next = NULL;
    customNode(int n){
        data = n;
    }
};

class CustomStack{
    int size = 0;
    int count = 0;
    customNode* Top = NULL;
    public:
    CustomStack(int capacity){
        if(capacity<=0){
            // cout<<"cannot create stack with size<=0\n";
            exit(1);
        }
        this->size = capacity;
        // cout<<"new Stack created with capacity to hold "<<capacity<<" elements\n";
    }
    bool is_empty(){
        if(Top==NULL) return true;
        else return false;
    }
    bool is_full(){
        if(this->count==this->size) return true;
        else return false;
    }
    int top(){
        if(is_empty()){
            // cout<<"stack is empty\n";
            return 0;
        }
        return Top->data;
    }
    void push(int n){
        if(this->is_full()){
            cout<<"stack is full, can not push given element "<< n <<"\n";
        }else{
            customNode* new_node = (customNode*)malloc(1*sizeof(customNode));
            new_node->next = Top;
            Top = new_node;
            Top->data = n;
            this->count++;
            // cout<<"element "<<n<<" appended at the top of the stack\n";
        }
    }
    int pop(){
        if(this->is_empty()){
            cout<<"stack is empty, can not pop\n";
            return INT_MIN;
        }else{
            customNode* new_node;
            new_node = Top;
            Top = Top->next;
            int n = new_node->data;
            free(new_node);
            new_node = NULL;
            this->count--;
            // cout<<"element "<<n<<" at the top of the stack is removed\n";
            return n;
        }
    }
    void printStack(){
        if(is_empty()) cout<<"Stack is empty\n";
        else{
            cout<<"The elements in the Stack are as follows :\nTop->[";
            customNode* temp = Top;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"]\n";
        }

    }
};

void printArr(vector<int> &arr){
    cout<<"[ ";
    for(auto elem:arr){
        cout<<elem<<" ";
    }
    cout<<"]\n";
    return;
}

void nexGreaterInt(CustomStack&a,CustomStack&b,vector<int>& ans,int len,int n){
    if(n>=len) return;
    if(len<=1){
        ans.push_back(-1);
        return;
    }
    else{
        while (!b.is_empty()) a.push(b.pop());
        int x  = a.pop();
        int z = 0;
        bool found = false;
        while (!a.is_empty()){
            if(!found&&a.top()>x){
                found  = true;
                z = a.top();
            }
            b.push(a.pop());
        }
        b.push(x);
        found?ans.push_back(z):ans.push_back(-1);
    }
    n++;
    nexGreaterInt(a,b,ans,len,n);
}

int main(){
    vector<int> circular_arr = {1,2,3,4,3};
    vector<int> ans;
    cout<<"The given array is :";
    printArr(circular_arr);

    int len = circular_arr.size();
    CustomStack a(len);
    CustomStack b(len);
    for(int i = 0;i<len;i++) b.push(circular_arr[i]);
    nexGreaterInt(a,b,ans,len,0);
    
    cout<<"The NextGreaterInteger array is :";
    printArr(ans);
    
    return 0;
}