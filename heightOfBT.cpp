#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int Height(node* root){
    if(root==NULL){
        return 0;
    }
    else
    {// Height of root->left = HL
    int HL = Height(root->left);
// Height of root->right = HR
    int HR = Height(root->right);
    return max(HL,HR)+1;}
}
int main(){
     node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<Height(root)<<endl;
    return 0;
}
