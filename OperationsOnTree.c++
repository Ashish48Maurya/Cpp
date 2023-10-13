#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Node* root = NULL;
            // OR //
class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }
};

void insertBST(Node* &root, int val){
    if(root==NULL){
        Node* newNode = new Node(val);
        root=newNode;
        return;
    }
    if (val < root->data) {
        insertBST(root->left, val);
    } else {
        insertBST(root->right, val);
    }
}

bool searchNode(Node* root , int val){
    if(root==NULL){
        return false;
    }
    if(root->data > val){
        return searchNode(root->left , val);
    }
    else if(root->data < val){
        return searchNode(root->right , val);
    }
    return true;
}

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int main(){
    cout<<endl;
    BST bst1;
    insertBST(bst1.root, 3);
    insertBST(bst1.root, 1);
    insertBST(bst1.root, 4);
    insertBST(bst1.root, 6);
    insertBST(bst1.root, 2);
    // inOrderTraversal(bst1.root);

    if(searchNode(bst1.root,4)){
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element Not Found"<<endl;
    }

    free(bst1.root);
    cout<<endl;
    return 0;
}