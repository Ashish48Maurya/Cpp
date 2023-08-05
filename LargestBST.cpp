#include<iostream>
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
class Info{
public:
    bool isBST;
    int size;
    int min;
    int max;
    int ans;
};

int main(){
    return 0;
}