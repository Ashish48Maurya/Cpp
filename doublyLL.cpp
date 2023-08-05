#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node* &head , int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    if(head==NULL){
        head = new_node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = new_node;
}


void deleteAtHead(Node* &head){
    Node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void delete_node(Node* &head , int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(temp!=NULL and count!=pos){
        temp=temp->next;
        count++;
    }
    if(temp->next != NULL){
        temp->prev->next = temp->next;
    }
    temp->next = temp->prev;
    delete temp;
}


void insertAtPosition(Node* &head , int val, int pos){
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(temp!=NULL and count<pos-1){
        temp=temp->next;
        count++;
    }
    Node* new_node = new Node(val);
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
}


int length(Node* &head){ 
    int l=0;
    Node* temp =head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}



void display(Node* &head){
Node* temp = head;
while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
}
}

int main(){
    // Node* new_node = new Node(3);
    // cout<<new_node->val<<endl;

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtTail(head,5);
    insertAtHead(head,1);
    insertAtTail(head,4);
    insertAtTail(head,7);
    display(head);
    cout<<endl;
    // delete_node(head,3);
    // display(head);

    // insertAtPosition(head,9,6);
    // display(head);
    return 0;
}