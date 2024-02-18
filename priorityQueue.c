
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node *temp , *start = NULL, *node = NULL;

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data, int priority) {
    node = createNode(data, priority);
    
    if (start == NULL || priority > start->priority) {
        node->next = start;
        start = node;
    }
    else {
        temp = start;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
}


int dequeue() {
    if (start == NULL) {
        printf("Priority queue is empty\n");
        return -1;
    }
    temp = start;
    int data = temp->data;
    start = start->next;
    free(temp);
    return data;
}


void display() {
    if (start == NULL) {
        return;
    }
    temp = start;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    
    enqueue(10, 3);
    enqueue(20, 2);
    enqueue(30, 4);
    enqueue(40, 1);

    printf("Priority Queue: ");
    display();
    printf("\n");

    int dequeued = dequeue();
    printf("Dequeued: %d\n", dequeued);

    printf("Priority Queue after dequeue: ");
    display();
    return 0;
}