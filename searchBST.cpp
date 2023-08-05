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
node* searchInBST(node* root,int key){
    if(root->data==key){
        return root;
    }
    if(root==NULL){
        return NULL;
    }
    if(root->data>key){
        return root->left = searchInBST(root->left,key);
    }
      
    else {return root->right = searchInBST(root->right,key);}
}
int main(){
    node* root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->left = new node(2);
    root->right->right = new node(4);
    if(searchInBST(root,7)==NULL){
        cout<<"Key doen't Exist"<<endl;
    }
    else{
        cout<<"Key Exist"<<endl;
    }
return 0;
}