#include<iostream>
using namespace std;
void towerofHanoi(int n, char src, char dest, char help){
    if (n==0){return;}
    towerofHanoi(n-1,src,help,dest);
    //n-1 discs ko source rod se helper rod tak pohochao;
    cout<<"move from"<<" "<<src<<" "<<"to"<<" "<<dest<<endl;
    towerofHanoi(n-1,help,dest,src);

}

int main(){
    towerofHanoi(3,'A','c','B');
    return 0;
}