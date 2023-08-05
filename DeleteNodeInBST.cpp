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

node* inorderSuccessor(node* root){
    node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
node* DeleteBST(node* root , int key){
    if(root->data > key){
        root->left = DeleteBST(root->left,key);
    }
    else if(root->data < key){
        root->right = DeleteBST(root->right,key);
    }
    else{
     if(root->left == NULL and root->right == NULL){
            return NULL;
        }
     if(root->left == NULL){
        node* temp = root->right;
        free(root);
        return temp;
     }
     else if(root->right == NULL){
        node* temp = root->left;
        free(root);
        return temp;
     }
     node* IS = inorderSuccessor(root->right);
       { root->data = IS->data;
        root->right = DeleteBST(root->right,IS->data);}
    }

    return root;
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
node* root = new node(3);
root->left = new node(2);
root->right = new node(7);
root->left->left = new node(1);
root->right->right = new node(8);
root->right->left = new node(5);
root->right->left->right = new node(6);
root->right->left->left = new node(4);

inorderTra(root);
cout<<endl;
//root = DeleteBST(root,5);
//root = DeleteBST(root,1);
root = DeleteBST(root,2);
inorderTra(root);
return 0;
}