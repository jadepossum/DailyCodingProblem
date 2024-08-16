#include<iostream>
using namespace std;

class customNode{
    public:
        int data;
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
            cout<<"cannot create stack with size<=0\n";
            exit(1);
        }
        this->size = capacity;
        cout<<"new Stack created with capacity to hold "<<capacity<<" elements\n";

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
            cout<<"stack is empty\n";
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
            cout<<"element "<<n<<" appended at the top of the stack\n";
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
            cout<<"element "<<n<<" at the top of the stack is removed\n";
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

class customQueue{
    customNode* start = NULL;
    customNode* end = NULL;
    int size = 0;
    int count = 0;
    public:
    customQueue(int n){
        if(n<=0){
            cout<<"cannot create stack with size<=0\n";
            exit(1);
        }
        this->size = n;
        cout<<"new Queue created with capacity to hold "<<n<<" elements\n";
    }
    bool is_empty(){
        if(this->start==NULL) return true;
        else return false;
    }
    bool is_full(){
        if(this->count==this->size) return true;
        else return false;
    }
    void enqueue(int n){
        if(is_full()){
            cout<<"Queue is full, can not enqueue "<< n<<"\n";
        }else{
            customNode* new_node = new customNode(n);
            if(end == NULL){
                this->end = new_node;
                this->start = new_node;
            }
            else{
                this->end->next = new_node;
                this->end = new_node;
            }
            this->count++;
            cout<<"element "<<n<<" appended at the end of the Queue\n";
        }
    }
    int dequeue(){
        if(is_empty()){
            cout<<"Queue is empty, can not dequeue\n";
            return -1;
        }else{
            int n = this->start->data;;
            if(this->start->next == NULL){
                end = NULL;
                free(start);
                start=NULL;
            }else{
                customNode* new_node;
                new_node = this->start;
                this->start = this->start->next;
                this->count--;
                new_node->next=NULL;
                free(new_node);
                new_node = NULL;
            }
            cout<<"element "<<n<<" removed from the beginning of the Queue\n";
            return n;
        }
    }
    void printQueue(){
        if(is_empty()) cout<<"Queue is empty\n";
        else{
            cout<<"The elements in the Queue are as follows :\n start -> [";
            customNode* temp = start;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"] <- end\n";
        }

    }
};


int main(){

    CustomStack stk(5); //creating a stack object with limited capacity
    if(stk.is_empty()) cout<<"Stack is empty\n"; //checking if it is empty
    stk.push(3);    //pushing elements into the stack;
    stk.push(4);
    stk.push(5);
    stk.push(1);
    stk.push(2);
    stk.push(6);
    if(stk.is_full()) cout<<"Stack is full\n";  //checking if the stack is full
    int b = stk.top(); //popping the top element
    int a = stk.pop();
    int c = stk.top();
    cout<<"popped elements are :"<<a<<" "<<b<<" "<<c<<"\n";
    stk.printStack();   //printing the contents of the stack


    cout<<"\n";
    cout<<"\n";
    customQueue Q1(5);
    if(Q1.is_empty()) cout<<"Queue is empty\n";
    Q1.enqueue(5);
    Q1.enqueue(4);
    Q1.enqueue(7);
    Q1.enqueue(6);
    Q1.enqueue(3);
    Q1.enqueue(2);
    Q1.printQueue();
    if(Q1.is_full()) cout<<"Queue is full\n";
    a = Q1.dequeue();
    b = Q1.dequeue();
    c = Q1.dequeue();
    cout<<"removed elements are :"<<a<<" "<<b<<" "<<c<<"\n";
    Q1.dequeue();
    Q1.dequeue();
    Q1.dequeue();
    Q1.printQueue();

    cout<<"hello";
    

    return 0;
}