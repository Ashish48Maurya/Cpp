#include<iostream>
using namespace std;
int tillingways(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    //I have placed one tile in vertical manner , now board size left is 2*(n-1) and your task is to fill that vacant space
    int vertical = tillingways(n-1);
    //I have placed two tile in horizontal manner , now board size left is 2*(n-2) and your task is to fill that vacant space
    int horizontal = tillingways(n-2);
    return vertical + horizontal;
}
int main(){
    int n;
    cin>>n;
 cout<<tillingways(n);
return 0;
}