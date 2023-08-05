//   if input = 5;
//   then output -> 1 2 3 4 5
#include<iostream>
using namespace std;
void print(int n){
//Base Case
if(n<1){
    return;
}
//Assumption
print(n-1);
//Self Work
cout<<n<<" ";
}

int main(){
    int n; cin>>n;
    print(n);
    return 0;
}