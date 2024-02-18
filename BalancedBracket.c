#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
char expression[MAX];

char stack[MAX];
int top = -1;

void push(char character) {
    top++;
    stack[top] = character;
}

void pop() {
    if (top != -1) {
        top--;
    }
}

bool isEmpty() {
    return top == -1;
}

char topEle(){
    return stack[top];
}

bool isValidExpression(char* expression) {
    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(expression[i]);
        }
            else if(expression[i]==')'){
                if(topEle()=='('){
                    pop();
                }
                else{
                     return false;
                }
            }
            else if(expression[i]=='}'){
                if(topEle()=='{'){
                    pop();
                }
                else{
                     return false;
                }
            }
            else if(expression[i]==']'){
                if(topEle()=='['){
                    pop();
                }
                else{
                     return false;
                }
            }
        else{
            continue;
        }
    }

    return isEmpty();
}

int main() {
    printf("Enter an expression: ");
    scanf("%s",&expression);

    if (isValidExpression(expression)) {
        printf("Balanced parentheses\n");
    } else {
        printf("Balanced parentheses\n");
    }

    return 0;
}
