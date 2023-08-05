#include<iostream>
using namespace std;
int getBit(int n, int pos){
    return((n & (1<<pos))!=0);
}

int setBit(int n,int pos){
    return((n | (1<<pos)));
}

int clearBit(int n, int pos){
int mask= ~(1<<pos);
return (n & mask);}

int updateBit(int n, int pos, int value){
    if(value == 0){
        int mask = ~(1<<pos);
        return (n & mask);
    }
    else{
      return(n | (1<<pos));
    }
}

int main(){
   //  cout<<getBit(5,3)<<endl;
   // cout<<setBit(5,1);
   //cout<<clearBit(5,2);
   cout<<updateBit(5,2,0);
   cout<<endl;
   cout<<updateBit(5,1,1);
    return 0;
}