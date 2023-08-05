#include<iostream>
using namespace std;
int glo = 6;
void sum(){
    int a;
    cout<< glo;
}
int main(){
    int glo=9;
    glo=78;
    char c ='u';
    bool is_true = true;
    sum();
    cout<<"\n";
    cout<<glo<< is_true;
    return 0;
}