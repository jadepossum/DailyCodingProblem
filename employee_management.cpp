#include<iostream>
#include<string>
using namespace std;

class Employee{
    public:
    int id;
    string name;
    int salary;
};

int search_employee(Employee* arr,int req_id,int size){
    for(int i=0;i<size;i++){
        if(arr[i].id == req_id) return i;
    }
    return -1;
}

void sort_employee_by_salary(Employee* arr,int size){
    for(int i = 1;i<size;i++){
        Employee curr_emp = arr[i];
        while(i>0 && arr[i-1].salary > curr_emp.salary){
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = curr_emp;
    }
}
int main(){
    int len = 0;
    cout<<"Enter the number of employees : ";
    cin>>len;
    Employee emp_arr[len];;

    for(int i = 0;i<len;i++){
        cout<<"\nEnter employee details of Employee"<<i+1<<endl;
        cout<<"Enter id(int) :";
        cin>>emp_arr[i].id;
        cout<<"Enter name(string) :";
        cin>>emp_arr[i].name;
        cout<<"Enter salary(int) :";
        cin>>emp_arr[i].salary;
    }

    int required_id  = 0;
    cout<<"Enter the id of the required employee :";
    cin>>required_id;

    int id = search_employee(emp_arr,required_id,len);
    if(id!=-1){
        cout<<"\nemployee found at index : "<<id<<endl;
        cout<<"Employee details are : "<<endl;
        cout<<"name : "<<emp_arr[id].name<<" salary : "<<emp_arr[id].salary<<" id :" <<id<<endl;
    }else {
        cout<<"employee not found"<<endl;
    }

    cout<<"\nemployees before sorting by salary : "<<endl;
    for(int i = 0;i< len;i++){
        cout<<"Employee id : "<<emp_arr[i].id
            <<" salary : "<<emp_arr[i].salary
            <<" name : "<<emp_arr[i].name<<endl;
    }

    sort_employee_by_salary(emp_arr,len);
    cout<<"\nemployees after sorting by salary : "<<endl;
    for(int i = 0;i< len;i++){
        cout<<"Employee id : "<<emp_arr[i].id
        <<" salary : "<<emp_arr[i].salary
        <<" name : "<<emp_arr[i].name<<endl;
    }
}