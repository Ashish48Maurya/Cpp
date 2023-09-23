// In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.

#include <stdio.h>
#include <stdbool.h>
#define MAX 5
int circularQueue[MAX] = {0};
int front = -1;
int back = -1;

void push(int val)
{
    if (front == 0 && back == MAX - 1)
    {
        printf("Queue is Full\n");
    }
    else if (front == -1)
    {
        front = back = 0;
    }
    else if (back == MAX - 1 && front != 0)
    {
        back = 0;
    }
    else
    {
        back = (back + 1) % MAX;
    }
    circularQueue[back] = val;
}

void pop()
{
    if (front == -1)
    {
        printf("Queue is Empty");
    }
    else if (front == back)
    {
        front = back = -1;
    }
    front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }

    if (back >= front)
    {
        for (int i = front; i <= back; i++)
            printf("%d ", circularQueue[i]);
        printf("\n");
    }

    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d ", circularQueue[i]);
        }
        for (int i = 0; i <= back; i++)
        {
            printf("%d ", circularQueue[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(14);
    push(22);
    push(13);
    push(-6);

    display();

    pop();
    pop();

    display();

    push(9);
    push(20);
    push(5);

    display();

    pop();
    push(18);
    display();

    return 0;
}