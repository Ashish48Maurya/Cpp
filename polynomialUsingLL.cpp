#include<iostream>
using namespace std;
class Node{
    public:
    int coeff;
    int expo;
    Node* next;
    Node(int c, int e){
        coeff = c;
        expo = e;
        next = NULL;
    }
};

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->coeff<<"-"<<temp->expo<<" -> ";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void insertAtTail(Node* &head , int c, int e){
    Node *node = new Node(c , e);
    if(head==NULL){
        head = node;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = node;
    }
}

void addition(Node* head1, Node* head2, Node* &head3) {
    while (head1 && head2) {
        if (head1->expo == head2->expo) {
            int c = head1->coeff + head2->coeff;
            int e = head1->expo;
            insertAtTail(head3, c, e);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->expo > head2->expo) {
            insertAtTail(head3, head1->coeff, head1->expo);
            head1 = head1->next;
        } else {
            insertAtTail(head3, head2->coeff, head2->expo);
            head2 = head2->next;
        }
    }
    while (head1) {
        insertAtTail(head3, head1->coeff, head1->expo);
        head1 = head1->next;
    }
    while (head2) {
        insertAtTail(head3, head2->coeff, head2->expo);
        head2 = head2->next;
    }
}

int main(){
    Node* head1 = NULL;
    insertAtTail(head1,8,3);
    insertAtTail(head1,7,2);
    insertAtTail(head1,4,1);
    insertAtTail(head1,1,0);
    display(head1);

    Node* head2 = NULL;
    insertAtTail(head2,3,3);
    insertAtTail(head2,6,1);
    insertAtTail(head2,11,0);
    display(head2);

    Node* head3 =  NULL;
    addition(head1,head2,head3);
    display(head3);

    return 0;
}