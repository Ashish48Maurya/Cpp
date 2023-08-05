#include<stdio.h>

int main()
{
    int n1, n2, result;
    char op;
    printf("Enter n1 :");
    scanf("%d",&n1);
    printf("Enter n2 :");
    scanf("%d",&n2);
    printf("Enter op :");
    scanf(" %c",&op);

    if(op=='+')
    {
        result=n1+n2;
        printf("Result = %d",result);
    }
    else
    printf("Invalid\n");

    return 0;
}