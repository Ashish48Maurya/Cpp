#include<iostream>
using namespace std;
int countpath(int st, int en){
    if(st==en){return 1;}
    if(st>en){return 0;}
    int count=0;
    for(int i=1; i<=6; i++){
        count += countpath(st+i, en);
    }
    return count;
    if(st==en){return 1;}
    for(int i=)
}
int main(){
    cout<<countpath(0, 3)<<endl;
    return 0;
}