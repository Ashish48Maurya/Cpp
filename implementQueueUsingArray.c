#include <stdio.h>
#define MAX 100
int front = -1;
int back = -1;
int queue[MAX];

void enQueue(int val) {
    if (back == MAX - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) {
            front = back = 0;
            queue[back] = val;
        }else {
            queue[++back] = val;
        }
    }
}

void deQueue() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } 
    else {
        if (front > back) {
            front = back = -1;
            printf("Queue is Empty\n");
        }
        front++;
    }
}

int firstEle() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        for (int i = front; i <= back; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    printf("%d\n",firstEle());
    display();

    deQueue();
    deQueue();

    display();
    enQueue(4);
    enQueue(3);
    enQueue(2);
    printf("%d\n",firstEle());
    return 0;
}