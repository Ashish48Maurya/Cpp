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
node* Range(node* root, int k1, int k2){
    if(root==NULL){
        return NULL;
    }
    if(root->data >= k1 and root->data <= k2){
        cout<<root->data<<" ";
        Range(root->left,k1,k2);
        Range(root->right,k1,k2);
    }
    else if(root->data > k2){
        Range(root->right, k1, k2);
    }
    else{
        Range(root->left,k1,k2);
    }
    return root;
}
int main(){
    node* root = new node(8);
    root->left = new node(5);
    root->right = new node(10);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->right->right = new node(11);
    root->right->right->right = new node(14);
    root->left->left->left = new node(1);
    root->left->left->right = new  node(4);
    Range(root,5,12);
return 0;
}