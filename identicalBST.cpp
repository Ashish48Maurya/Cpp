#include<iostream>
using namespace std;
class node{
public:
 int data;
 node* right;
 node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
bool isIdentical(node* root1 , node* root2){
    if(root1==NULL and  root2==NULL){
        return true;
    }
    else if(root1==NULL or root2==NULL){
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left,root2->left);
        bool cond3 = isIdentical(root1->right,root2->right);
        if(cond1 and cond2 and cond3){
            return true;
        }
        else{
            return false;
        }
    }
    
}
int main(){
// node* root = new node(4);
// root->left = new node(3);
// root->right = new node(5);

node* root1 = new node(4);
root1->left = new node(3);
root1->right = new node(5);

node* root2 = new node(7);
root2->left = new node(5);
root2->right = new node(8);

if(isIdentical(root1,root2)){
    cout<<"BST's are Identical"<<endl;
}
else{
    cout<<"BST's are not Identical"<<endl;
}
return 0;
}