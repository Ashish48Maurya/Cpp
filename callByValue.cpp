// #include<stdio.h>
// void Swap(int a, int b){
//     int temp = a;
//     a=b;
//     b=temp;
//     printf("\nFrom swap function");
//     printf("\nValue of a is: %d",a);
//     printf("\nValue of b is: %d",b);
// }
// int main(){
//     int a=2,b=9;
//     printf("\nFrom Main function");
//     printf("\nValue of a is: %d",a);
//     printf("\nValue of b is: %d",b);
//     Swap(a,b);
//     printf("\nFrom main function");
//     printf("\nValue of a is: %d",a);
//     printf("\nValue of b is: %d",b);
//     return 0;
// }

#include<stdio.h>
void Swap(int a, int b){
    printf("\nIn Swap function");
    printf("\nAddress of a is: %p",&a);
    printf("\nAddress of b is: %p",&b);
}
int main(){
    int a=2,b=9;
    printf("\nIn Main function");
    printf("\nAddress of a is: %p",&a);
    printf("\nAddress of b is: %p",&b);

    Swap(a,b);
    return 0;
}