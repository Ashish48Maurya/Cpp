#include<iostream>
using namespace std;
void print1(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    print1(n-1);
}

// void print2(int n){
//     if(n==1){
//         cout<<n<<" ";
//         return;
//     }
//     print2(n-1);
//     cout<<n<<" ";
// }

int main(){
    int n;
    cin>>n;
    print1(n);
    // print2(n);
    return 0;
}