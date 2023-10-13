#include<stdio.h>
#include<stdlib.h>
int queueSize = 5;
int currentSize = 0;

struct Node{
    int data;
    struct Node *next;
};

struct Node *temp, *new_node , *start = NULL;

struct Node* createNode(int value){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    currentSize++;
    return node;
}

//Push from back
void enqueue(int value){
    new_node = createNode(value);
    if(start == NULL){
        start = new_node;
        return;
    }
    if(currentSize>queueSize){
        printf("Queue Full\n");
        return;
    }
    temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

//Pop from Start
void dequeue(){
    if(start == NULL){
        printf("Queue Empty\n");
        return;
    }
    start = start->next;
}

void frontElement(){
    if(start == NULL){
        printf("Queue Empty\n");
        return;
    }
    printf("%d\n",start->data);
}

void display(){
    if(start == NULL){
        printf("Queue Empty\n");
        return;
    }
    temp = start;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    frontElement();
    display();

    dequeue();
    frontElement();
    display();
    return 0;
}