// print node->data at a given level of Binary Tree
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
void kLevel(node* root, int level,int k){
    if(root==NULL){
        return;
    }
    if(level==k){
        cout<<root->data<<" ";
        return;
    }
    kLevel(root->left, level+1, k);
    kLevel(root->right, level+1, k);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    kLevel(root,1,3);
return 0;
}