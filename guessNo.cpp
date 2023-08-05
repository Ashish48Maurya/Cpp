#include<iostream>
using namespace std;
int main(){
int chances = 0;
int number = 72;
cout<<"Guess the number selected by me, which is in between 1 to 100: "<<endl;
int n;
cin>>n;
bool guessGame = true;
while(guessGame){
    if(n>72){
        cout<<"Your gussed number is, greater than actual number"<<endl;
        chances++;
        cin>>n;
    }
    else if(n<72){
        cout<<"Your gussed number is smaller than actual number"<<endl;
        chances++;
        cin>>n;
    }
    else{
        cout<<"Congratulations! ,You selected the correct Number"<<endl;
        //cout<<"बढ़ाई हो ! आप ने सही अंक चुना"<<endl;
        chances++;
        cout<<"Your Score is: "<<(100-chances)<<endl;
        //cout<<"आप का स्कोर हैं: "<<(100-chances)<<endl;
        break;
    }
}
return 0;
}