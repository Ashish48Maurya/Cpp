#include<iostream>
using namespace std;
void replacepie(string str){
    if(str.length()==0){
        return;
    }
    if(str[0]=='p' and str[1]=='i'){
        cout<<"3.14";
        replacepie(str.substr(2));
    }
    else{
        cout<<str[0];
        replacepie(str.substr(1));
    }
}
int main(){
    replacepie("pippiipi");
}