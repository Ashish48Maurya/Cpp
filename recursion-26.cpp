// check whether a given Number is Armstrong or not;


// Asumption -> from a number recursion will give me sum of cube of first two digits
//self work -> I have to do only addition of cube of last digit with the ans given by recursion
#include<iostream>
using namespace std;

int pow(int x, int y){
    if(y==0){
        return 1;
    }
    return x*pow(x,y-1);
}

int check(int n, int no_of_elements){
    if(n==0){
        return 0;
    }
    return pow(n%10,no_of_elements) + check(n/10,no_of_elements);
}

int main(){
int n;
cin>>n;
int no_of_elements = 0;
int temp = n;
while(temp>0){
  temp /= 10;   // temp = temp/10;
  ++no_of_elements;  
}
int ans = check(n,no_of_elements);
if(ans==n) cout<<"Yes";
else cout<<"No";
return 0;
}