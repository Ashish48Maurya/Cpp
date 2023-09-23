#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;
char *e;

char topEle()
{
    return stack[top];
}

void pop()
{
    top--;
}

void push(char e)
{
    stack[++top] = e;
}

int precedence(char e)
{
    if (e == '(')
    {
        return 0;
    }
    if (e == '*' || e == '/')
    {
        return 2;
    }
    if (e == '+' || e == '-')
    {
        return 1;
    }
    return -1;
}

int main()
{
    char str[100];
    printf("Enter Infix Expression: ");
    scanf("%s", str);
    e = str;
    while (*e != '\0')
    {
        if (*e == '(')
        {
            push(*e);
        }
        else if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == ')')
        {
            while (top != -1 && topEle() != '(')
            {
                printf("%c", topEle());
                pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(topEle()) >= precedence(*e))
            {
                printf("%c", topEle());
                pop();
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", topEle());
        pop();
    }
    return 0;
}