#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *node,*temp,*top=NULL;

struct Stack{
    int size;
    struct Node *top;
};
struct Stack *ele,*st;


struct Node* createNode(int data) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;
    return node;
}

struct Stack *createStack(){
    st = (struct Stack*)malloc(sizeof(struct Stack));
    st->top = NULL;
    st->size = 0;
    return st;
}

void push(int data){
    st->size++;
    node = createNode(data);
    if(st->top == NULL){
        st->top = node;
        return;
    }
    node->next = st->top;
    st->top = node;
}

bool isEmpty(){
    return st->top==NULL;
}

int topEle(){
    if(st->top==NULL){
        printf("Stack UnderFlow");
        return -1000;
    }
    int top = st->top->data;
    return top;
}

int pop(){
    if(st->top==NULL){
        printf("Stack UnderFlow");
        return -1000;
    }
    st->size--;
    temp = st->top;
    int ans = temp->data;
    st->top = temp->next;
    temp->next = NULL;
    free(temp);
    return ans;
}

void display(){
    if(st->top==NULL){
        printf("Stack UnderFlow");
        return;
    }
    temp = st->top;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }printf("\n");
}
int main(){
    st = createStack();
    display();
    printf("\n"); //1->True
    printf("%d\n",isEmpty());
    push(1);
    push(2);
    push(3);
    display();
    pop();
    pop();
    display();
    return 0;
}