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
int countTreeNode(node* root){
    if(root==NULL){
        return 0;
    }
    int ans = 1+countTreeNode(root->right)+countTreeNode(root->left);
}
bool isCBT(node* root, int i, int totalNode){
    if(root==NULL){
       return true;
    }
    if(i>totalNode){
        return false;
    }
    else{
        bool left = isCBT(root->left , 2*i , totalNode);
        bool right = isCBT(root->right , 2*i+1 , totalNode);
        return (left and right);
    }
}

bool isMaxHeap(node* root){
    if(root->left ==NULL and root->right ==NULL){
        return true;
    }
    if(root->right == NULL){
        return (root->left->data < root->data);
    }
    else{
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        if(left and right and (root->left->data < root->data)){
            return true;
        }
        else{
            return false;
        }
    }
}

bool isBT_heap(node* root){
    int index = 1;
    int totalNode = countTreeNode(root);
    if(isCBT(root,index,totalNode) and isMaxHeap(root)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
node* root = new node(60);
root->left = new node(80);
root->right = new node(40);
root->left->left = new node(30);
root->left->right = new node(20);
cout<<isBT_heap(root)<<endl;
return 0;
}