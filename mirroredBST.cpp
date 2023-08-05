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
node* mirroredBST(node* root){
    if(root==NULL){
        return NULL;
    }
    node* LS = mirroredBST(root->left);
    node* RS = mirroredBST(root->right);
    root->left = RS;
    root->right = LS;
}
void inorderTra(node* root){
    if(root==NULL){
        return;
    }
    inorderTra(root->left);
    cout<<root->data<<" ";
    inorderTra(root->right);
}
int main(){
    node* root = new node(8);
    root->left = new node(5);
    root->right = new node(10);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->right->right = new node(3);
    inorderTra(root);
    cout<<endl;
    mirroredBST(root);
    inorderTra(root);
    return 0;
}