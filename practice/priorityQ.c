#include <stdio.h>
#include<ctype.h>
#include <stdbool.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

void pop() {
    top--;
}

char topEle() {
    return stack[top];
}

bool empty() {
    return top == -1;
}

bool isValid(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
         else if (ch == ')') {
            if (empty() || topEle() != '(') {
                return false;
            }
            pop();
        } else if (ch == ']') {
            if (empty() || topEle() != '[') {
                return false;
            }
            pop();
        } else if (ch == '}') {
            if (empty() || topEle() != '{') {
                return false;
            }
            pop();
        }
        i++;
    }
    return empty();
}

int main() {
    char str[MAX] = "{A{S(H[I]S)H}}";
    // char str[MAX] = "{{([))}}";

    if (isValid(str)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
