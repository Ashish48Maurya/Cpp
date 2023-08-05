#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};


void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        new_node=head;
        new_node->next = new_node;
        return ;
    }
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->next = head;
}

void deleteAtStart(Node* &head){
if(head==NULL){
    return;
}
Node* temp = head;
Node* tail = head;
while(tail->next != head){
    tail=tail->next;
}
head = head->next;
tail->next = head;
delete temp;
}

void deleteAtEnd(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    Node* tail = temp->next;
    temp->next = head;
    delete tail;
}


void insertAtHead(Node* &head, int val){
    Node* new_head = new Node(val);
    if(head==NULL){
        head = new_head;
        new_head->next = new_head; //To make LL circular
        return;
    }
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    tail->next = new_head;
    new_head->next = head;
    new_head  = head;
}


void isCircular(Node* &head){
Node* temp = head;
for(int i=0; i<12; i++){
    cout<<temp->val<<"->";
    temp = temp->next;
}cout<<endl;
}

void display(Node* &head){
    Node* temp = head;
    do{
        cout<<temp->val<<"->";
        temp = temp->next;
    }while(temp != head);
}

int main(){
Node* head = NULL;
insertAtHead(head,1);
insertAtHead(head,2);
insertAtHead(head,3);
insertAtHead(head,4);
display(head);
cout<<endl;
// isCircular(head);
insertAtTail(head,6);
insertAtTail(head,5);
display(head);
cout<<endl;
deleteAtStart(head);
display(head);
cout<<endl;
deleteAtEnd(head);
display(head);
cout<<endl;
return 0;
}