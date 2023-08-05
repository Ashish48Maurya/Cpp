#include<iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T val;
    Node* next;
    Node(T data){
        val = data;
        next = NULL;
    }
};
int main(){
Node<int>* int_node = new Node<int> (3);
Node<char>* char_node = new Node<char> ('a');
cout<<int_node->val<<endl;
cout<<char_node->val<<endl;
return 0;
}