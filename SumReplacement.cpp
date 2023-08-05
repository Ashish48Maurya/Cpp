#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data= val;
        left=NULL;
        right=NULL;
    }
};
void SumReplacement(node* root){
   if(root==NULL){
    return ;
   }
   SumReplacement(root->left);
   SumReplacement(root->right);

   if(root->left){
    // OR if(root->left != NULL)
    root->data += root->left->data;
   }
    if(root->right){
    root->data += root->right->data;
   }
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    cout<<endl;
    SumReplacement(root);
    preorder(root);
return 0;
}