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

void calculateSize(node *root, int &left,int position, int &right){
    if(root==NULL){
        return;
    }
    left = min(left,position);
    right = max(right,position);

    calculateSize(root->left, left,position-1, right);
    calculateSize(root->right, left,position+1, right);
}


int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(7);
    root->right->right = new node(6);

    int left = 0;
    int right = 0;
    calculateSize(root, left, 0, right);

    vector<vector<int>> negative(abs(left)+1);
    vector<vector<int>> positive(right+1);
    queue<node*> q;
    queue<int> idx;

    q.push(root);
    idx.push(0);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        int index = idx.front();
        idx.pop();

        if(index < 0){
            negative[abs(index)].push_back(temp->data);
        }

        if(index >= 0){
            positive[index].push_back(temp->data);
        }

        if(temp->left){
            q.push(temp->left);
            idx.push(index-1);
        }

        if(temp->right){
            q.push(temp->right);
            idx.push(index+1);
        }
    }

    vector<int> tempV;

    for(int i=negative.size()-1; i>=0; i--){
        for(int j=0; j<negative[i].size(); j++){
            tempV.push_back(negative[i][j]);
        }
    }

    for(int i=0; i<positive.size(); i++){
        for(int j=0; j<positive[i].size(); j++){
            tempV.push_back(positive[i][j]);
        }
    }

    for(auto i : tempV){
        cout<<i<<" ";
    }
    return 0;
}