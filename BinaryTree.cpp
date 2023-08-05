#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* Left;
    node* Right;
    node(int val){
        data = val;
        Left = NULL;
        Right = NULL;
    }
};
int main(){
    node* root = new node(1);
    root->Left = new node(2);
    root->Right = new node(3);
    root->Left->Left = new node(4);
    root->Left->Right = new node(5);
    root->Right->Left = new node(6);
    root->Right->Right = new node(7);
    return 0;
}