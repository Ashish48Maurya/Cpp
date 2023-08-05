//Even position node after odd position node
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
// constructor formation
    node(int val){
        data=val;
        next=NULL;
    }
};
void evenAfterOdd(node* &head){
    //Even number of nodes ke liye
    node* odd =head;
    node* even = head->next;
    node* evenStart = head->next;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
     odd->next=evenStart;
     //Odd number of nodes ke liye
     if(odd->next!=NULL){
        even->next=NULL;
     }
}
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp->next=n;
        n->next=head;
        head=n;
    }
}
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* temp= head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = n;
    n->next= head;
}
void Display(node* &head){
   node* temp = head;
  do{
    cout<<temp->data<<"->";
    temp=temp->next;
  }while(temp!=head);
   cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    Display(head);
    evenAfterOdd(head);
    Display(head);
return 0;
}