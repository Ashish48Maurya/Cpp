#include<iostream>
using namespace std;
bool isPossible(int arr[],int start, int end,int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i=0; i<n; i++){
        if(pageSum+arr[i]<=mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int pageAllocate(int arr[],int n, int m){
    //n = no. of books
    //m = no. of student
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int start = 0 , end=sum;
    int mid = (start+end)/2;
    int ans=-1;
    while(start<=end)
    {
        if(isPossible(arr,start,end,n,m,mid)){
        ans=mid;
        end = mid-1;
    }
    else{
        start = mid+1;
    }
    mid = (start+end)/2;
    }
    return ans;
}
int main(){
int arr[] = {10,20,30,40};
int Pp = pageAllocate(arr,4,2);
if(Pp==-1){
    cout<<"Allocation not possible"<<endl;
}
else{
    cout<<"Allocation possible with min no. of pages: "<<Pp<<endl;
}
return 0;
}