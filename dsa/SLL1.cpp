#include<iostream>
using namespace  std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(Node* &head,int  val){
    Node* n=new Node(val);
    Node* Temp=head;
    if(head==NULL){
        head=n;
        return;
    }
    while(Temp->next!=NULL){
        Temp=Temp->next;
    }
    Temp->next=n;
}
void insertAtHead(Node* &head,int val){
    Node* n=new Node(val);
     if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
}
void deleteAtHead(Node* &head){
    Node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(Node* &head,int val){
    //For No Node present
    if(head==NULL){
        return;
    }
    //For present only one Node
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    Node* Temp=head;
    while(Temp->next->data!=val){
        Temp=Temp->next;
    }
    Node* todelete=Temp->next;
    Temp->next=Temp->next->next;
     delete todelete;   
     //Avoid Memory Leak
}
void display(Node* head){
      Node* Temp=head;
      while(Temp!=NULL){
        cout<<Temp->data<<"->";
        Temp=Temp->next;
      }
      cout<<"NULL"<<endl;
}
bool search(Node* head,int key){
    Node* Temp=head;
    while(Temp!=NULL){
        if(Temp->data==key){
            return true;
        }
        Temp=Temp->next;
    }
    return false;
}
Node* reverse(Node* &head){
    Node* prevptr=NULL;
    Node* currPtr=head;
    Node* nextptr;
    while(currPtr!=NULL){
        nextptr=currPtr->next;
        currPtr->next=prevptr;
        prevptr=currPtr;
        currPtr=nextptr;
    }
    return prevptr;
}
Node* reverseRecursive(Node* &head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* newNode=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newNode;
}
Node* reversek(Node* &head,int k){
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
         }
    if(nextptr!=NULL ){
            head->next=reversek(nextptr,k);
        }
    return prevptr;

}
void evenAfterOdd(Node* &head) {
Node* odd = head;
Node* even = head->next;
Node* evenStart = even;
while (odd->next != NULL && even->next != NULL) {
odd->next = even->next;
odd = odd->next;
even->next = odd->next;
even = even->next;
}
odd->next = evenStart;
if (odd->next != NULL) {
even->next = NULL;
}
}
int main(){
       Node* head=NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,8);
    // insertAtTail(head,0);
    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // insertAtTail(head,7);
    // display(head);
    // insertAtHead(head,0);
    // display(head);
    // cout<<search(head,97);
    // cout<<endl;
    // //deletion(head,1);
    // deleteAtHead(head);
    // display(head);
    // //Node* newNode=reverse(head);
    // //display(newNode);
    // //Node* newNode=reverseRecursive(head);
    // Node* newNode=reversek(head,4);
    // display(newNode);
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    evenAfterOdd(head);
    display(head);
}