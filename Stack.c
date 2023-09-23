#include <stdio.h>
#define MAX 10

int top = -1;
int stack[MAX];

void push(int num)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow \n");
        return;
    }
    top++;
    stack[top] = num;
    printf("\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow \n");
        return;
    }
    top--;
    printf("\n");
}

void display()
{
    if (top == -1)
    {
        printf("Stack Underflow \n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void topEle()
{
    if (top == -1)
    {
        printf("Stack Underflow \n");
        return;
    }
    printf("%d\n", stack[top]);
}

int main()
{
    int choice;
    int num;
    do
    {
        printf("Enter 1 for push 2 for pop 3 for display  4 for top element and 5 for terminate ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Element u want to push: ");
            scanf("%d", &num);
            push(num);
            break;

        case 2:
            if (top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("Element Popped is %d \n", stack[top]);
                pop();
            }
            break;

        case 3:
            printf("Stack is: ");
            display();
            break;

        case 4:
            if (top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("Top Element is %d\n", stack[top]);
            }
            break;

        case 5:
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
