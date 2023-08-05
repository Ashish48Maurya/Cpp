//Queue implimentation using Linked-List
#include<iostream>
using namespace std;
class Node{
    public:

    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class Queue{
    public: 

    Node* head;
    int size;
    Node* tail;

    Queue(){
        this->size = 0;
        this->head=NULL;
        this->tail=NULL;
    }
    
    void enqueue(int data){
        Node* node = new Node(data);
        size++;
        if(head==NULL and tail==NULL){ //if first node
            head=tail=node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }

    void dequeue(){
        size--;
        if(head==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else{
            Node* oldHead = head;
            Node* newHead = head->next;
            head = newHead;
            if(head==NULL){  //if there is single node pointed by head and u updated head pointer then it will surely pointing to NULL in such case or when newHead is pointing to NULL(Possible in case of single Node);
                tail=NULL;
            }
            oldHead->next = NULL;
            free(oldHead);
        }
    }

    bool isEmpty(){
        return head == NULL;
    }

    int length(){
        if(head==NULL){
            return -1;
        }
        return size;
    }

    int topEle(){
        if(head==NULL){
            return -1;
        }
        return head->data;
    }
};

int main(){
Queue qu;
cout<<qu.isEmpty()<<endl;
qu.enqueue(1);
qu.enqueue(2);
qu.enqueue(3);
cout<<qu.length()<<endl;
cout<<qu.topEle()<<endl;
qu.enqueue(4);
qu.enqueue(5);
cout<<qu.topEle()<<endl;
cout<<qu.length()<<endl;
cout<<qu.isEmpty()<<endl;
qu.dequeue();
cout<<qu.length()<<endl;
return 0;
}