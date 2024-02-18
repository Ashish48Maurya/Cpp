                    //Circular LL
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

void Display(node* &head){
   node* temp = head;
  do{
    cout<<temp->data<<"->";
    temp=temp->next;
  }while(temp!=head);
   cout<<"NULL"<<endl;
}