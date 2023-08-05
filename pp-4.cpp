#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    const int N = 1e6;
    bool check[N];
    for(int i=0; i<n; i++){
        check[i] = 0;
    }
    for(int i=0; i<n; i++){
        if(array[i]>= 0){
            check[array[i]] = 1;
        }
    }
    int ans=-1;    // ye else ka kaam bhi kar raha hai aur ans kis format me hai wo bhi bata raha hai
    for(int i=1; i<N; i++){
        if(check[i] = 0);
        ans = i;
        break;
        cout<<ans;
    }
    return 0;
}