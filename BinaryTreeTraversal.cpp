#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* Left;
    node* Right;
    node(int val){
        data=val;
        Left = NULL;
        Right = NULL;
    }
};

void inOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->Left);
    cout<<root->data<<" ";
    inOrderTraversal(root->Right);
}
void preorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->Left);
    preorderTraversal(root->Right);
}
void postorderTraversal(node* root){
     if(root==NULL){
        return;
    }
    postorderTraversal(root->Left);
    postorderTraversal(root->Right);
    cout<<root->data<<" ";
}
int main(){
   node* root  = new node(1);
   root->Left = new node(2);
   root->Right = new node(3);
   root->Left->Left = new node(4);
   root->Left->Right = new node(5);
   root->Right->Left = new node(6);
   root->Right->Right = new node(7);

   inOrderTraversal(root);
   cout<<endl;
   preorderTraversal(root);
   cout<<endl;
   postorderTraversal(root);
   cout<<endl;
return 0;
}