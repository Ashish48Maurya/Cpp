// first occurence of a particular number in array
#include<iostream>
using namespace std;
int firstocc(int A[], int n, int i, int key){
    if(i==n){return -1; }
    if(A[i]== key){
        return i;
    }
    return firstocc(A,n,i+1,key);
}

int lastocc(int arr[],int n,int i,int key){

    if(i==n){return -1;}
    int restarr=lastocc(arr,n,i+1,key);
    if(restarr != -1){return restarr;}
    if(arr[i] == key){return i;}
    return -1;
}

int main(){
    int A[]={4,2,1,2,5,2,7};
    cout<<firstocc(A,7,0,2);
    int arr[]={4,2,1,2,5,2,7};
    cout<<lastocc(arr,7,0,2);
}