// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node* next;
// };

// int position = 0 , dataValue = 0, count , sum , avg;
// struct Node *node , *temp , *del , *start = NULL;

// struct Node* createNode(int value){
//     struct Node *p = (struct Node*)malloc(sizeof(struct Node));
//     p->data = value;
//     p->next = NULL;
//     return p;
// } 

// void insertLast(int value){
//     node = createNode(value);
//     if(start==NULL){
//         start = node;
//         return;
//     }
//     temp = start;
//     while(temp->next!=NULL){
//         temp = temp->next;
//     }
//     temp->next = node;
// }

// void insertInBtw(int value){
//     node = createNode(value);
//     printf("Enter Position: ");
//     scanf("%d",&position);
//     temp = start;
//     for(int i=1; i<position-1; i++){
//         temp = temp->next;
//     }
//     node->next = temp->next;
//     temp->next = node;
// }

// void display(){
//     temp = start;
//     while(temp!=NULL){
//         printf("%d->",temp->data);
//         temp = temp->next;
//     }printf("NULL");
// }

// void deleteByValue(){
//     printf("Enter Data value: ");
//     scanf("%d",&dataValue);
//     temp = start;
//     if(dataValue == start->data){
//         del = start;
//         start = start->next;
//         return;
//     }
//     else{
//         while(temp->next->data!=dataValue){
//         temp = temp->next;
//         }
//     del = temp->next;
//     temp->next = del->next;
//     }
//     free(del);
// }
// int noOfNodes(){
//     count = 1;
//     temp = start;
//     if(start==NULL){
//         return 0;
//     }
//     while(temp->next!=NULL){
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// int SumOfNodes(){
//     sum = 0;
//     if(start==NULL){
//         return 0;
//     }
//     temp = start;
//     while(temp!=NULL){
//         sum += temp->data;
//         temp = temp->next;
//     }
//     return sum;
// }

// int averageOfNode(){
//     if(start==NULL){
//         return 0;
//     }
//     avg = SumOfNodes()/noOfNodes();
//     return avg;
// }

// int main(){
//     insertLast(1);
//     insertLast(5);
//     insertLast(3);
//     insertLast(4);
//     display();
//     deleteByValue();
//     display();
//     // printf("\n");
//     // printf("%d",averageOfNode());
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Dequeue {
    struct Node* front;
    struct Node* rear;
};

struct Dequeue* createDequeue() {
    struct Dequeue* dq = (struct Dequeue*)malloc(sizeof(struct Dequeue));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

int isEmpty(struct Dequeue* dq) {
    return dq->front == NULL;
}

void insertFront(struct Dequeue* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (isEmpty(dq)) {
        newNode->prev = NULL;
        newNode->next = NULL;
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = NULL;
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void insertRear(struct Dequeue* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = dq->rear;
    newNode->next = NULL;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

int deleteFront(struct Dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty\n");
        return -1;
    }

    int data = dq->front->data;
    struct Node* temp = dq->front;
    
    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    return data;
}

void display(struct Dequeue *dq){
    if(dq->front == NULL){
        return;
    }
    struct Node *temp = dq->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Dequeue *dq = createDequeue();
    insertFront(dq,1);
    insertFront(dq,2);
    insertRear(dq,3);
    insertRear(dq,4);
    display(dq);
    printf("\n");
    deleteFront(dq);
    display(dq);
    return 0;
}
