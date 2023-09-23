#include<iostream>
using namespace std;
void printTable(int num, int multiple){
    if(multiple==1){
        cout<<num<<" * "<<multiple<<" = "<<num*multiple<<endl;
        return;
    }
    printTable(num,multiple-1);
    cout<<num<<" * "<<multiple<<" = "<<num*multiple<<endl; 
}

int main(){
    int num,multiple;
    cin>>num>>multiple;
    printTable(num,multiple);
    return 0;
}