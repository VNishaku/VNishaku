#include<iostream>
using namespace std;
#define n 100
class Stack{
    int* arr;
    int top;
    public:
    Stack(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow\n";
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"No elemment in Stack\n";
            return -1;
        }
        return arr[top];
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.isempty()<<endl;
}