#include<iostream>
using namespace std;
int main(){
    for(int i=0; i<11; i++){
        cout<<i<<endl;
        i++;
    }
 //   cout<<i<<endl;      {This will throw an error because i is local variable which is defined under for loop only}
return 0;
}