#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    } 
};
Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
Node* searchInBST(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}
Node* inordersucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* deleteInBST(Node* root,int key){
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }else {
        if(root->left==NULL){
        Node* temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        Node* temp=root->left;
        free(root);
        return temp;
    }
    Node* temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data); 
    } 
    return root;
}
void PreOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int search(int inorder[],int start,int end, int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
/*Node* buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder,start,end,curr);
    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);
    return node;
}*/
Node* buildTree(int postorder[],int inorder[],int start,int end){
    static int idx=4;
    if(start>end){
        return NULL;
    }
    int val=postorder[idx];
    idx--;
    Node* curr=new Node(val);
    if(start==end){
        return curr;
    }
    int pos=search(inorder,start,end,val);
    curr->left=buildTree(postorder,inorder,pos+1,end);
    curr->right=buildTree(postorder,inorder,start,pos-1);
    return curr;
}
void inorderPrint(Node* root){
    if(root==NULL){
        return ;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
void printLevelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        else if(!q.empty())
        q.push(NULL);
    }
}
int calHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int LH=calHeight(root->left);
    int RH=calHeight(root->right);
    return max(LH,RH)+1;
}
bool isbalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isbalanced(root->left)==false){
        return false;
    }
    if(isbalanced(root->right)==false){
        return false;
    } 
    int LH=calHeight(root->left);
    int RH=calHeight(root->right);
    if(abs(LH-RH)<=1){
        return true;
    }else{
        return false;
    }
}
int main(){
     //struct Node* root=new Node(1);
    // root->left=new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // cout<<"preorder:";
    // PreOrder(root);
    // cout<<endl;
    // cout<<"inorder:";
    // InOrder(root);
    // cout<<endl;
    // cout<<"postorder:";
    // PostOrder(root);
   // int preorder[]={1,2,4,3,5};
//    int postorder[]={4,2,5,3,1};
//     int inorder[]={4,2,1,5,3};
//     Node* root=buildTree(postorder,inorder,0,4);
//     inorderPrint(root);
//   Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->right = new Node(5);
//     root->left->left = new Node(4);
//      root->right->right = new Node(7);
//     root->right->left = new Node(6);
//     root->right->right->left=new Node(9);
//     printLevelOrder(root);
//     cout<<endl;
//     cout<<"Height: "<<calHeight(root)<<endl;
//     cout<<"IsBalance:"<<isbalanced(root);
Node* root=NULL;
root=insertBST(root,6);
insertBST(root,5);
insertBST(root,3);
insertBST(root,1);
insertBST(root,4);
insertBST(root,2);
InOrder(root);
int y;
cout<<"y:";
int key;
cout<<"key";
cin>>key;
cin>>y;
if(searchInBST(root,5)==NULL){
    cout<<"key doesn't exits\n";
}else{
   //searchInBST(root,y);
    cout<<"key exits\n";
}
cout<<endl;
root=deleteInBST(root,5);
InOrder(root);
cout<<endl;
      return 0;
} 
