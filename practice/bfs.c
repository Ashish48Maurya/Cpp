                                //BFS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* node, *temp;

struct Queue {
    int size;
    struct Node* head;
    struct Node* tail;
};

struct Queue* queue;

struct Queue* createQueue() {
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;
    return node;
}

void enqueue(int data) {
    queue->size++;
    node = createNode(data);
    if (queue->head == NULL) {
        queue->head = queue->tail = node;
    }
    queue->tail->next = node;
    queue->tail = node;
}

int dequeue() {
    if (queue->head == NULL) {
        printf("Queue is empty");
        return 0;
    }
    queue->size--;
    temp = queue->head;
    queue->head = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display() {
    if (queue->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = queue->head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

bool isEmpty() {
    return queue->head == NULL;
}

int main() {
    queue = createQueue();
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int matrix[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 1, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1, 0, 0},
                        {0, 0, 1, 1, 0, 1, 1},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0}};

    visited[i] = 1;
    enqueue(i);
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        for (int j = 0; j < 7; j++) {
            if (matrix[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
    return 0;
}