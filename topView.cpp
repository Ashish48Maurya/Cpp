#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) { 
        data = val;
        left = NULL;
        right = NULL;
    }
};

void calculateSize(Node *root, int &leftMost, int position, int &rightMost) {
    if (root == 0) {
        return;
    }
    leftMost = min(position, leftMost);
    rightMost = max(rightMost, position);
    calculateSize(root->left, leftMost, position - 1, rightMost);
    calculateSize(root->right, leftMost, position + 1, rightMost);
}

void topView(Node *root, vector<int> &ans, vector<int> &filled, int left) {
    int LEFT = -left;
    if (root == NULL) {
        return;
    }
    queue<Node*> storeNode;
    queue<int> storeIndex;
    storeNode.push(root);
    storeIndex.push(LEFT);

    while (!storeNode.empty()) {
        Node *temp = storeNode.front();
        storeNode.pop();
        int index = storeIndex.front();
        storeIndex.pop();

        if (filled[index] == 0) {
            filled[index] = 1;
            ans[index] = temp->data;
        }

        if (temp->left) {
            storeNode.push(temp->left); 
            storeIndex.push(index - 1);
        }
        if (temp->right) {
            storeNode.push(temp->right);
            storeIndex.push(index + 1);
        }
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(6);

    int left = 0;
    int right = 0;
    calculateSize(root, left, 0, right);

    vector<int> ans(right - left + 1);
    vector<int> filled(right - left + 1, 0);
    topView(root, ans, filled, left);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
