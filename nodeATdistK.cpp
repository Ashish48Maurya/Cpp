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
// case-1
// K is target node here
void printSubtreeNode(node* root, int k){
    if(root==NULL or k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    printSubtreeNode(root->left,k-1);
    printSubtreeNode(root->right,k-1);
}
// case-2
// target is LCA here
int printNodeAtK(node* root, node* target, int k){
    if(root==NULL){
        return -1;
    }
    if(root == target){
        printSubtreeNode(root,k);
        return 0;
    }
    int dr = printNodeAtK(root,target,k);
        if(dr != -1){
            if(dr+1==k){
                cout<<root->data<<" ";
            }
            else{
                printSubtreeNode(root->left,k-dr-2);
            }
            return -1;
        }
    }
int main(){
node* root = new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left  = new node(4);
root->left->right = new node(5);
root->right->left = new node(6);
root->right->right = new node(7);
printSubtreeNode(root,3);
return 0;
}