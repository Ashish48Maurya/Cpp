#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data = data;
        next = prev = NULL;
    }
};

Node *head = NULL;

void insertAtHead(int data){
    Node* node = new Node(data);
    if(head==NULL){
        head = node;
        return;
    }
    Node *temp = head;
    node->next = temp;
    temp->prev = node;
    node->prev = NULL;
    head = node;
}

void insertAtTail(int data){
    Node* node = new Node(data);
    if(head==NULL){
        head = node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    node->next = NULL;
}

void insertAtBw(int value){
    int pos;
    cin>>pos;
    if(pos==1){
        insertAtHead(value);
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos-1; i++){
        temp = temp->next;
    }
    Node *node = new Node(value);
    node->next = temp->next;
    node->prev = temp;
    temp->next = node;
    temp->next->prev = node;
}

void deleteFront(){
    if(head==NULL){return;}
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteEnd(){
    if(head==NULL){
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node *del = temp;
    temp->prev->next = NULL;
    free(del);
}

void deleteBw(){
    int pos;
    cin>>pos;
    Node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtTail(4);
    insertAtTail(5);
    insertAtTail(6);
    // insertAtBw(5);
    display();
    // deleteFront();
    // display();
    // deleteEnd();
    // deleteBw();
    // display();


    return 0;
}