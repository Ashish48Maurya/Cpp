#include<stdio.h>
#include<stdlib.h>
struct Node{
    int c;
    int e;
    struct Node *next;
};

struct Node *temp , *temp2 , *temp1 , *node, *list=NULL , *list2=NULL , *ans=NULL;

struct Node *createNode(int c, int e){
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->c = c;
    temp->e = e;
    temp->next = NULL;
    return temp;
}

struct Node* InsertAtTail(int cons, int exp , struct Node* start){
    node = createNode(cons,exp);
    if(start==NULL){
        start = node;
        return start;
    }
    temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = node;
    return start;
}

void display(struct Node *start){
    temp = start;
    if(start==NULL){
        return;
    }
    while(temp!=NULL){
        printf("[%d %d] ->",temp->c,temp->e);
        temp = temp->next;
    }
    printf("NULL");
}

struct Node* summation(struct Node* list, struct Node* list2, struct Node* ans) {
    temp1 = list;
    temp2 = list2;
    ans = createNode(0, 0);  // Initialize ans with a dummy node
    temp = ans;

    while (temp1 && temp2) {
        temp->next = createNode(0, 0);

        if (temp1->e == temp2->e) {
            temp->next->c = temp1->c + temp2->c;
            temp->next->e = temp1->e;

            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->e > temp2->e) {
            temp->next->c = temp1->c;
            temp->next->e = temp1->e;

            temp1 = temp1->next;
        } else {
            temp->next->c = temp2->c;
            temp->next->e = temp2->e;

            temp2 = temp2->next;
        }

        temp = temp->next;
    }

    while (temp1) {
        temp->next = createNode(temp1->c, temp1->e);
        temp1 = temp1->next;
        temp = temp->next;
    }

    while (temp2) {
        temp->next = createNode(temp2->c, temp2->e);
        temp2 = temp2->next;
        temp = temp->next;
    }

    return ans->next;  // Skip the dummy node at the beginning
}



int main(){
    list = InsertAtTail(1, 1, list);
    InsertAtTail(9, 2, list);
    InsertAtTail(2, 3, list);
    InsertAtTail(5, 4, list);
    display(list);
    printf("\n");


    list2 = InsertAtTail(3, 1, list2);
    InsertAtTail(9, 2, list2);
    InsertAtTail(6, 3, list2);
    InsertAtTail(2, 4, list2);
    display(list2);
    printf("\n");

    struct Node* ANS = summation(list,list2,ans);
    display(ANS);
    return 0;
}