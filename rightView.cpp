#include<iostream>
#include<queue>
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
void rightView(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
     int n = q.size();
     for(int i=0; i<n; i++){
        node* Node = q.front();
        q.pop();
        if(i==n-1){
            cout<<Node->data<<" ";
        }
        if(Node->left != NULL){
        q.push(Node->left);
        }
        if(Node->right != NULL){
        q.push(Node->right);
        }
        }
   }
    
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->left = new node(7);
    rightView(root);
    return 0;
}