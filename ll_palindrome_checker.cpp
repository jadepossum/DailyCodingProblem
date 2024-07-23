#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
    Node(){this->data = 0;}
    Node(int x){this->data = x;}
};

//O(n) S(1)
bool palindrome_checker_1(Node* head){
    Node* temp1 = head;
    Node* temp2 = head;
    int count = 0;
    while(temp1!=NULL){
        count+=1;
        temp1 = temp1->next;
    }
    temp2 = NULL;
    temp1 = head;
    for(int i = 0;i<count/2;i++){
        temp1 = head;
        head = head->next;
        temp1->next = temp2;
        temp2 = temp1;
    }
    if(count%2==1){
        head=head->next;
    }
    while(temp2!=NULL){
            if(temp2->data!=head->data) return false;
            temp2 = temp2->next;
            head = head->next;
        }
    return true;
}

// O(n^2) S(1)
bool palindrome_checker_2(Node* head){
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp1!=NULL){
        temp2 = temp1;
        while(temp2->next->next!=NULL){
            temp2=temp2->next;
        }
        if(temp1->data!=temp2->next->data) return false;
        temp2->next=NULL;
        temp1 = temp1->next;
    }
    return true;
}
// O(n) & S(n)
bool palindrome_checker_3(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int len = arr.size();
    for(int i = 0;i<len/2;i++){
        if(arr[i]!=arr[len-1-i])
            return false;
    }
    return true;
}
int main(){
    Node a(1);
    Node b(2);
    Node e(2);
    Node c(2);
    Node d(1);
    a.next = &b;
    b.next = &e;
    e.next = &c;
    c.next = &d;

    Node* head = &a;
    cout<<"The linked list is as follows :";
    while(head!=NULL){
        cout<<" "<<head->data<<"->";
        head = head->next;
    }
    head = &a;
    cout<<"NULL"<<endl;
    if(palindrome_checker_1(head)){
        cout<<"[ O(n) S(1) ] It is a palindrome "<<endl;
    }
    else{
        cout<<"It is not a palindrome"<<endl;
    }
    return 0;
}