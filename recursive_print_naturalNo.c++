//print Natural Number Till n With Alternate Sign
#include<iostream>
using namespace std;
int sum = 0;
void print(int n){
    if(n==1){
        cout<<n<<" ";
        sum+=1;
        return;
    }
    print(n-1);
    if(n%2 == 0){
        cout<<-n<<" ";
        sum = sum - n;
    }
    if(n%2 != 0){
        cout<<n<<" ";
        sum = sum + n;
    }
}

int main(){
    int n;
    cin>>n;
    print(n);
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}