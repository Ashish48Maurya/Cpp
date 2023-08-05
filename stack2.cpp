//Stack Implementaion by LinkedList;
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
       this->data = val;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* head;
    int capacity;
    int currSize;

    Stack(int size){
        this->capacity = size;
        this->currSize = 0;
        this->head = NULL;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(currSize==capacity){
            return 1;
        }
        return 0;
    }

    void push(int ele){
        if(currSize==capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        Node* new_node = new Node(ele);
        new_node->next = head;
        head = new_node;
        currSize++;
    }

    void pop(){
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* new_head = head->next;
        head->next = NULL;
        free(head);
        head = new_head;
    }

    int topEle(){
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return head->data;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(4);
    st.pop();
    cout<<st.topEle()<<endl;
    return 0;
}