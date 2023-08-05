// #include<iostream>
// #include<climits>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;

//     int array[n];
//     for(int i=0; i<n; i++){
//         cin>>array[i];
//     }

//     int maxNo =INT_MIN;
//     int minNo =INT_MAX;
//     for(int i=0; i<n; i++){
//         if(array[i]>maxNo){
//             maxNo=array[i];
//         }
//         if(array[i]<minNo){
//             minNo=array[i];
//         }  
//     }
//     cout<<maxNo<<" "<<minNo<<endl;
//     return 0;
// }


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int max=arr[0] , min=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }

    cout<<"max is: "<<max<<" & "<<"min is: "<<min<<endl;
    return 0;
}