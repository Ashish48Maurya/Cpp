#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
}; 
node* LCA(node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1  or root->data==n2){
        return root;
    }
    node* leftLCA = LCA(root->left,n1,n2);
    node* rightLCA = LCA(root->right,n1,n2);
    if(root->left != NULL  and root->right != NULL){
        return root;
    }
   if(leftLCA != NULL  and rightLCA == NULL){
    return leftLCA;
   }
   else{
    return rightLCA;
   }
}
int main(){
node* root = new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(5);
root->right->left = new node(6);
root->right->right = new node(7);
node* lca = LCA(root,4,7);
if(lca==NULL){
    cout<<"LCA doen't exist"<<endl;
}
else{
    cout<<"LCA: "<<lca->data<<endl;
}
return 0;
}