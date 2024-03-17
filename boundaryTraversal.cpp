#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int value){
        left=NULL;
        right=NULL;
        data=value;
    }
};

void leftSub(node *root, vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left){
        ans.push_back(root->data);
        leftSub(root->left, ans); 
    }
    if(root->right){
        ans.push_back(root->data);
    }
    leftSub(root->right, ans); 
}


void leaf(node *root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        ans.push_back(root->data);
    }
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void rightSub(node *root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->right){
        rightSub(root->right,ans);
    }
    ans.push_back(root->data);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(9);
    root->left->right = new node(5);
    root->right->left = new node(7);
    root->right->right = new node(6);

    vector<int> ans;
    //Add Root Node
    ans.push_back(root->data);
    //Add Node of left subtree except the last Node(leaf Node)
    leftSub(root->left,ans);
    //Add all the leaf Node including the node which was left in the above case
    leaf(root,ans);
    //Add all the Nodes of the right Subtree excluding the root Node(obv because we have considered it in first Case) and last Node of right subtree, also make sure to print it in reverse order
    rightSub(root->right,ans);

    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}