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
int Height(node* root){
    if(root==NULL){
        return 0;
    }
    int HL = Height(root->left);
    int HR = Height(root->right);
    return max(HL,HR)+1;
}
bool isBalanced(node* root){
    if(root==NULL){
        return false;
    }
// agar check kar liye leftsubtree ko aur wo unbalanced aa gaya toh yahi se return kar jaayenge aage jaa ke time waste q kare
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    int HL , HR;
    if(abs(HL-HR)<=1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    root->left->left = new node(4);
    root->left->left->left = new node(5);
    if(isBalanced(root)){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is Unbalanced"<<endl;
    }
return 0;
}