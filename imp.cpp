// int a=4;
// b=a;

// a++
// a++ ka toh wahi value rahegaa jo 'a' ka tha intially par iske baad 'a' ka value 'a+1' ho jaayegaa
// ++a 
// instantly 'a' ka value 'a+1' hojayyega or fir 'a' ka value bhi 'a+1' hojayyega 

//         Eg
#include<iostream>
using namespace std;
int main(){

    int i=1;
    int j=5;
    int k;


//                     5       3 because iske pahale i ka value 2 ho chukka hai
    k= i + j + i++  +  j++  +  ++i   +   ++j ;
//    1    5   1 par cout me i hai uska value change hoke abhi 2 ho jaayega

    cout<<i<< " " <<j<< " "  <<k;


    return 0;
}


//  %-----> this sign represents remainder in coding

//  += ----> this sign represents  in coding  see eg below
// if a+=b   implies  ;   a=a+b