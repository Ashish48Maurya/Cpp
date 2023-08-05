// input:  num=2, k=4
// output:  2 4 6 8
#include<iostream>
using namespace std;
void print(int num, int k){
    if(k==0){
        return;
    }
    print(num,k-1);
    printf("%d ",num*k);
}
int main(){
print(2,4);
return 0;
}


// #include<stdio.h>
// int main(){
// int num = 2, k=4;
// for(int i=1; i<=k; i++){
//     printf("%d ",num*i);
// }
// return 0;
// }