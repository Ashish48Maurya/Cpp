#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Node* root = NULL;
            // OR //
class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }
};

void insertBST(Node* &root, int val){
    if(root==NULL){
        Node* newNode = new Node(val);
        root=newNode;
        return;
    }
    if (val < root->data) {
        insertBST(root->left, val);
    } else {
        insertBST(root->right, val);
    }
}

bool searchNode(Node* root , int val){
    if(root==NULL){
        return false;
    }
    if(root->data > val){
        return searchNode(root->left , val);
    }
    else if(root->data < val){
        return searchNode(root->right , val);
    }
    return true;
}


Node *maxValueNode(Node* root){
    Node *temp =  root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

Node *minValueNode(Node* root){
    Node *temp =  root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* &root, int value){
    if(root==NULL){
        return root;
    }
    if(root->data >  value){
        root->left = deleteNode(root->left , value);
    }
    else if(root->data <  value){
        root->right = deleteNode(root->right , value);
    }
    else{   //Node is to be deleted is Found;
        if(root->left == NULL && root->right == NULL){   //Node has 0 Child Node
            free(root);
            return NULL;
        }
        else if(root->left == NULL){        //Node has 1 Child Node
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){       //Node has 1 Child Node
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{                               //Node has 2 Child Node
            Node *justSmallestNode = maxValueNode(root->left);
            root->data = justSmallestNode->data;
            root->left = deleteNode(root->left , justSmallestNode->data);
        }
    }
    return root;
}

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void levelOrderTraversal(Node* root){

    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int numberOfNodes = q.size();
        // while(numberOfNodes!=0)     
        //          OR
        while(numberOfNodes--){
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }
    }
}

//We will use level Order Traversal Here
vector<int> rightView(Node* root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int numberOfNodes = q.size();
        while(numberOfNodes!=0){
            Node* currNode = q.front();
            q.pop();
            if(numberOfNodes==1){
                ans.push_back(currNode->data);
            }
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }
    }
    return ans;
}

int maxHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSubtreeHeight = maxHeight(root->left);
    int rightSubtreeHeight = maxHeight(root->right);
    return (max(leftSubtreeHeight , rightSubtreeHeight) + 1);
}   


//Predecessor and Successor of a given Key
void preSuccKey(Node *root, Node *&pre, Node *&succ, int key){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        if(root->left!=NULL){
            Node *temp  = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            pre = temp;
        }
        if(root->right!=NULL){
            Node *temp = root->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }
    if(root->data > key){
        succ = root;
        preSuccKey(root->left,pre,succ,key);
    }
    else if(root->data < key){
        pre = root;
        preSuccKey(root->right,pre,succ,key);
    }
    return;
}


//Lowest Common Ansector
Node* LCA(Node *root, Node *node1, Node *node2){
    if(node1==NULL && node2==NULL){
        return NULL;
    }
    if(root->data > node1->data || root->data > node2->data){
        //lca will be present at left part
        return  LCA(root->left,node1,node2);
    }
    if(root->data < node1->data || root->data < node2->data){
        //lca will be present at right part
        return  LCA(root->right,node1,node2);
    }
    //if one node > root and another node < root
    return root;
}


Node *removeLeafNode(Node *root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    
}

int main(){
    cout<<endl;
    BST bst1;
    //50,30,70,20,40,60,80
    insertBST(bst1.root , 50);  //It is the root Node of Our BST
    insertBST(bst1.root , 30);
    insertBST(bst1.root , 70);
    inOrderTraversal(bst1.root);cout<<endl;
    insertBST(bst1.root , 20);
    insertBST(bst1.root , 40);
    inOrderTraversal(bst1.root);cout<<endl;
    insertBST(bst1.root , 60);
    insertBST(bst1.root , 80);
    inOrderTraversal(bst1.root);cout<<endl;

    // if(searchNode(bst1.root,40)){
    //     cout<<"Element Found"<<endl;
    // }
    // else{
    //     cout<<"Element Not Found"<<endl;
    // }

    // cout<<maxValueNode(bst1.root)->data<<endl;
    // cout<<minValueNode(bst1.root)->data<<endl;

    //Node having 0 Child Node
    // deleteNode(bst1.root , 40);
    // inOrderTraversal(bst1.root);cout<<endl;

    //Node having 1 child Node 
    // deleteNode(bst1.root , 30);
    // inOrderTraversal(bst1.root);cout<<endl;

    //Node having 2 Child Node
    // deleteNode(bst1.root , 30);
    // inOrderTraversal(bst1.root);cout<<endl;

    // free(bst1.root);

    // Node* rootNode = new Node(1);
    // rootNode->left = new Node(2);
    // rootNode->right = new Node(3);
    // rootNode->left->left = new Node(4);
    // rootNode->left->right = new Node(5);
    // rootNode->right->left = new Node(6);
    // rootNode->right->right =  new Node(7);
    // // levelOrderTraversal(rootNode);

    // // rootNode->right->right->right =  new Node(8);
    // // cout<<maxHeight(rootNode)<<endl;

    // vector<int> ans = rightView(rootNode);
    // for(auto ele:ans){
    //     cout<<ele<<" ";
    // }

    // free(rootNode);



    // Node *pre = NULL;
    // Node *succ = NULL;
    // preSuccKey(bst1.root,pre,succ,80);
    // if(pre!=NULL){
    //     cout<<"pre-> "<<pre->data<<endl;
    // }
    // else{
    //     cout<<"pre-> NULL"<<endl;
    // }
    // if(succ!=NULL){
    //     cout<<"succ-> "<<succ->data<<endl;
    // }
    // else{
    //     cout<<"succ-> NULL"<<endl;
    // }


    // Node *node1 = new Node(20);
    // Node *node2 = new Node(40);
    // Node *ans = LCA(bst1.root,node1,node2);
    // cout<<"LCA is: "<<ans->data<<endl;



    return 0;
}