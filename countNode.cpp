#include<iostream>
using namespace std;
class node{
public:
int data;
node* Left;
node* Right;
    node(int val){
        data=val;
        Left=NULL;
        Right=NULL;
    }
};
int CountNode(node* root){
    if(root==NULL){
        // koi node nahi hai issliye zero
        return 0;
    }
    CountNode(root->Left);
    CountNode(root->Right);
    return CountNode(root->Left)+CountNode(root->Right)+1;
}
int main(){
    node* root = new node(1);
    root->Left = new node(2);
    root->Right = new node(3);
    root->Left->Left = new node(4);
    root->Left->Right = new node(5);
    root->Right->Left = new node(6);
    root->Right->Right = new node(7);
    cout<<CountNode(root);
return 0;
}