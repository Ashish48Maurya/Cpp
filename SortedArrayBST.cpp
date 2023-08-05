// Build BST from Sorted Array
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
void inorderTra(node* root){
    if(root==NULL){
        return;
    }
    inorderTra(root->left);
    cout<<root->data<<" ";
    inorderTra(root->right);
}
node* BSTFromSortedArray(int arr[], int start, int end){
    int mid = (start+end)/2;
    node* root = new node(arr[mid]);
    if(start>end){
        return NULL;
    }
    root->left = BSTFromSortedArray(arr,start,mid-1);
    root->right = BSTFromSortedArray(arr,mid+1,end);
    return root;
}
int main(){
int arr[] = {10,20,30,40,50};
node* root = BSTFromSortedArray(arr,0,4);
inorderTra(root);
return 0;
}