#include<stdio.h>
int main(){
    int x = 10;
    float y = 10.2;
    // int *ptr = &y;  --> throwing an error Saying, ki pointer ka datatype match karna chaiye jisko wo point kar raha hai uske datatype se
    //float *ptr = &y;

    //but void pointer kisi bhi datatype wale ka address store kar sakta hai


    // void *ptr = &y;
    // printf("Address of y is: %p",ptr);

    void *ptr = &y;
    ptr = &x;
    printf("Address of y is: %p",ptr);
    //printf("Value of x is: %d",*ptr);   --> throwing an error because  we cannot directly dereference void pointer therefore it must be type casted
    int *integerPointer = (int *)ptr;
    printf("\nValue of x is: %d",*integerPointer);
    return 0;
}