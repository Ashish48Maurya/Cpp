#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int value){
        data = value;
        left = right = NULL;
    }
};

int calculateSum(node *root,int &sum){
    if(!root){
        return 0;
    }
    if(!root->left and !root->right){
        return root->data;
    }

    int left = calculateSum(root->left,sum);
    int right = calculateSum(root->right,sum);

    if(root->left and root->right){
        sum = max(sum,root->data+left+right);
        return root->data + max(left,right);
    }
    if(root->left){
        return left+root->data;
    }
    if(root->right){
        return right+root->data;
    }
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(9);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int sum = 0;
    int finalAns = 0;
    calculateSum(root, sum);
    if(root->left && root->right){
        finalAns = sum;
    }
    else{
        finalAns = max(sum, root->data);
    }
    cout << finalAns << endl;
    return 0;
}
