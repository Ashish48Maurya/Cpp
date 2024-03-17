#include<iostream>
#include<vector>
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

void leftView(node *root , vector<int> &ans, int level){
    if(root==NULL){
        return;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    leftView(root->left , ans, level+1);
    leftView(root->right , ans, level+1);
}

int main(){
    vector<int> ans;
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->left = new node(7);
    root->right->left->left = new node(9);
    
    leftView(root,ans,0);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}