#include<iostream>        // convert given lower case word in upper case 
#include<string>
using namespace std;
int main(){
    string str="ashish";
    for(int i=0; i<str.size(); i++){
        if(str[i]>='a' && str[i]<='z');
        str[i] = str[i] - 32;
    }
    cout<<str<<endl;
    return 0;
}