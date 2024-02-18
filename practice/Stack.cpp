// #include <stdio.h>
// #include <stdbool.h>
// #define MAX 10

// int top = -1;
// int stack[MAX];

// void push(int num)
// {
//     if (top == MAX - 1)
//     {
       
//         return;
//     }
//     stack[++top] = num;

// }

// void pop()
// {
//     if (top == -1)
//     {
        
//         return;
//     }
//     top--;
// }

// int topEle()
// {
//     if (top == -1)
//     {
//         return -1;
//     }
//     return stack[top];
// }

// bool Empty(){
//     if(top==-1){
//         return true;
//     }
//     return false;
// }

// void nge(int arr[], int size){
//     int output[size];
//     push(0);
//     for(int i=1; i<size; i++){
//         while(!Empty() && arr[i]>arr[topEle()]){
//             output[topEle()] = arr[i];
//             pop();
//         }
//         push(i);
//     }

//     while(!Empty()){
//         output[topEle()] = -1;
//         pop();
//     }

//     for(int i=0; i<size; i++){
//         printf("%d ",output[i]);
//     }
// }

// int main()
// {
   
//     int arr[] = {100,4,78,92,45,63,99};
//     // ans -> {-1,78,92,99,63,99,-1};
//     //ans2 -> {-1,100,100,100,92,92,100};
//     //ans3 -> {4,-1,45,45,-1,-1,-1}
//     nge(arr,7);
//     return 0;
// }