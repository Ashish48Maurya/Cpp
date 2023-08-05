
#include<iostream>
using namespace std;
int main(){

    int i=1;
    int j=5;
    int k;

//    1   5     1       2       3      5
   k= i + j  +  i++  +  i++  +  i++ +  ++i ;
    cout<<i<< " " <<j<< " "  <<k;
     // value of i intially is 1 and  after i++ value of 
    //i becomes 2 and after again i++ value of i becomes 3 and so on and further after ++i value
    // of i becomes 5

    return 0;
}