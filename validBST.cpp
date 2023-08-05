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
bool ValidBST(node* root, node* min=NULL, node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data>=max->data){
        return false;
    }
    bool leftValid = ValidBST(root->left,min,root);
    bool rightValid = ValidBST(root->right,root,max);

    return leftValid and rightValid;
}
int main(){
node* root = new node(3);
root->left = new node(2);
root->right = new node(7);
root->left->left = new node(1);
root->right->right = new node(8);
root->right->left = new node(5);
root->right->left->right = new node(6);
root->right->left->left = new node(4);
if(ValidBST(root,NULL,NULL)){
    cout<<"BST is valid"<<endl;
}
else{
    cout<<"BST is invalid"<<endl;
}
return 0;
}