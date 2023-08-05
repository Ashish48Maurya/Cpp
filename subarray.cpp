#include<iostream>
using namespace std;
int main(){
int arr[] = {1,2,0,7,2,0,2};
for(int i=0; i<7; i++){
    for(int j=i; j<7; j++){
        for(int k=i; k<=j; k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
return 0;
}