#include<iostream>
#include<map>
#include<vector>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
 node(int val){
    data=val;
    left = NULL;
    right = NULL;
 }
};
void getVertOrder(node* root, int horid, map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[horid].push_back(root->data);
    getVertOrder(root->left,horid-1,m);
    getVertOrder(root->right,horid+1,m);
}
int main(){
node* root = new node(10);
root->left = new node(7);
root->right = new node(4);
root->left->left = new node(3);
root->left->right = new node(11);
root->right->left = new node(14);
root->right->right = new node(6);

map<int,vector<int>> m;
int horid = 0;
getVertOrder(root,horid,m);
map<int,vector<int>> :: iterator it ;
for(int it = m.begin() ; it != m.end() ; it++){
    for(int i=0; i<((it->second).size()); i++){
        cout<<(it->second)[i]<<" ";
    }
    cout<<endl;
}
return 0;
}