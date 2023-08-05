#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
bool isIdentical(node* Node, node* subroot){
    if(Node==NULL and subroot==NULL){
        return true;
    }
   else if(Node==NULL || subroot==NULL || Node->data  != subroot->data){
    return false;
   }
   // agar Node and subroot ke left ka pattern identical na ho toh return false
  if(!isIdentical(Node->left,subroot->left)){
    return false;
  }
  if(!isIdentical(Node->right,subroot->right)){
    return false;
  }
    return true;
}
bool subTree(node* root , node* subroot){
    if(root==NULL){
        return false;
    }
    if(root->data == subroot->data){
        if(isIdentical(root,subroot)){
            return true;
        }
    }
   return (subTree(root->right,subroot) || subTree(root->left,subroot));
   
}
int main(){
node* root = new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left  = new node(4);
root->left->right = new node(5);
root->right->left = new node(6);
root->right->right = new node(7);

node* subroot = new node(2);
subroot->left = new node(4);
subroot->right = new node(5);
cout<<subTree(root,subroot);
return 0;
}