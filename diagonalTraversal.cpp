#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int value){
        left=NULL;
        right=NULL;
        data=value;
    }
};

void findSize(node *root, int pos, int &l){
    if(root==NULL)
        return;
    l = max(l,pos);
    findSize(root->left,pos+1,l);
    findSize(root->right,pos,l);
}


void findDig(node *root, int pos, vector<vector<int>> &v){
    if(root==NULL)
    return;

    v[pos].push_back(root->data);
    findDig(root->left, pos+1, v);
    findDig(root->right,pos, v);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(9);
    root->left->right = new node(5);
    root->right->left = new node(7);
    root->right->right = new node(6);
    int l = 0;
    findSize(root,0,l);
    vector<vector<int>> v(l+1);
    findDig(root,0,v);

    vector<int> temp;
    for(int j=0; j<v.size(); j++){
        for(int i=0; i<v[j].size(); i++){
            temp.push_back(v[j][i]);
        }
    }

    for(auto i:temp){
        cout<<i<<" ";
    }
    return 0;
}