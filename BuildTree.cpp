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
int search(int inorder[],int start,int end,int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
        return i;
        }
    }
    return -1;
}
node* buildTree(int preorder[],int inorder[],int start,int end){
    if(start>end){
    return 0;
   }
   static int idx = 0;
   int curr = preorder[idx];
   idx++;
   node* Node = new node(curr);
  if(start==end){
    return Node;
  }
  if(Node!=NULL){
   int pos = search(inorder,start,end,curr);
   Node->left = buildTree(preorder,inorder,start,pos-1);
   Node->right = buildTree(preorder,inorder,pos+1,end);
   return Node;
  }
}
void inOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int main(){
   int preorder[] = {1,2,4,3,5};
   int inorder[] = {4,2,1,5,3};
   node* root = buildTree(preorder,inorder,0,4);
   inOrderTraversal(root);
return 0;
}