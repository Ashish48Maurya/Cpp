#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data= val;
        left=NULL;
        right=NULL;
    }
};
int Height(node* root){
    if(root==NULL){
        return 0;
    }
    return max(Height(root->left),Height(root->right))+1;
}
int Diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int HL=Height(root->left);
    int HR=Height(root->right);
    int DL = Diameter(root->left);
    int DR =Diameter(root->right);

    int SelfDiameter = HL+HR+1;
    return max(max(DL,DR),SelfDiameter);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right=new node(8);
    cout<<Diameter(root)<<endl;
return 0;
}