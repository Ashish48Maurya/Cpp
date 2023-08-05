#include<iostream>
using namespace std;
int sum(int a , int b){
    return a+b;
}
int sum(int a, int b, int c){
    return a+b+c;
}
int volume(int a){
    return a*a*a;
}
int main(){
    cout<<"The sum of 3 and 4 is: "<<sum(3,4)<<endl;
    cout<<"The sum  of 3, 4 and 1 is: "<<sum(3,4,1)<<endl;
    cout<<"The volume of square with side length 3 is: "<<volume(3)<<endl;
return 0;
}