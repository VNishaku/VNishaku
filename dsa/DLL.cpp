#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* previous;
    node(int val){
        data=val;
        next=NULL;
        previous=NULL;
    }
};
void insertAthead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    if(head!=NULL)
    {
    head->previous=n;
    }
    head=n;
}
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL)
    {
        //head=n;
        insertAthead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->previous=temp;
}
void insertAtPos(node* &head,int val,int pos)
{
    node* n=new node(val);
    node* temp=head;
    node* po=temp->next;
    
    if(head==NULL || pos==1)
    {
        insertAthead(head,val);
        return;
    }
   
    int count=2;
    while(count!=pos)
    {
       temp=temp->next;
        if(temp->next==NULL)
    {
        insertAtTail(head,val);
        return;
    }
       po=po->next;
      count++;
    }
   
    temp->next=n;
    n->previous=temp;
    n->next=po;
    po->previous=n;
    
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<""<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAthead(node* &head){
    node* todelete=head;
    head=head->next;
    head->previous=NULL;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteAthead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
          temp=temp->next;
          count++;
    }
    temp->previous->next=temp->next;
    if(temp->next!=NULL){
        temp->next->previous=temp->previous;
    }
    delete temp;
}
int main(){
    cout<<"DLL\n";
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAthead(head,0);
    display(head);
    insertAtPos(head,7,2);
    deleteAthead(head);
    deletion(head,3);
    display(head);
    cout<<"end";
    return 0;
}