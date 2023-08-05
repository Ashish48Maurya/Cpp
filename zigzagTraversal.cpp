#include<iostream>
#include<stack>
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
void zigzagTraversal(node* root){
    if(root==NULL){
        return;
    }
    stack<node*> currLevel;
    stack<node*> nextLevel;

    bool leftToright = true;
    currLevel.push(root);
    while(!currLevel.empty()){
        node* temp = currLevel.top();
        currLevel.pop();

        if(temp != NULL){
            cout<<temp->data<<" ";
            if(leftToright == true){
                if(temp->left != NULL){
                    nextLevel.push(temp->left);
                }
                if(temp->right != NULL){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
                leftToright = !leftToright;
                swap(currLevel, nextLevel);
            }
    }
}
int main(){
node* root =new node(12);
root->left = new node(9);
root->right = new node(15);
root->left->left = new node(5);
root->left->right = new node(10);
zigzagTraversal(root);
cout<<endl;
return 0;
}