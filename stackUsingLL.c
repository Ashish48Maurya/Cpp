#include<stdio.h>
#include<stdlib.h>
int stackSize = 5;
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

void push(int value){
    new_node = createNode(value);
    if(start == NULL){
        start = new_node;
        return;
    }
    if(currentSize>stackSize){
        printf("Stack Overflow\n");
        return;
    }
    temp = new_node;
    temp->next = start;
    start = temp;
}

void pop(){
    if(start == NULL){
        printf("Stack UnderFlow\n");
        return;
    }
    start = start->next;
}

void topElement(){
    if(start == NULL){
        printf("Stack UnderFlow\n");
        return;
    }
    printf("%d\n",start->data);
}

void display(){
    if(start == NULL){
        printf("Stack UnderFlow\n");
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
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    topElement();
    display();

    pop();
    topElement();
    display();
    return 0;
}