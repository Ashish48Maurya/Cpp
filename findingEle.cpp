//       Find second largest element in array if all element are unique

// #include<iostream>
// #include<climits>
// using namespace std;
// int largestelement(int arr[]){
// int max = INT_MIN;
// int maxIndex = -1;
//     for(int i=0; i<7; i++){
//         if(arr[i]>max){
//             max=arr[i];
//             maxIndex = i;
//         }
//     }
//     return maxIndex;
// }
// int main(){
// int arr[] = {2,3,4,1,5,7,8};
// int largestele = largestelement(arr);
// cout<<"The 1st largest element in array is: "<<arr[largestele]<<endl;
// cout<<"The index of 1st largest element is: "<<largestele<<endl;
// arr[largestele] = -1;
// int secMax = INT_MIN;
// for(int i=0; i<7; i++){
//     if(arr[secMax]<arr[i]){
//         arr[secMax]=arr[i];
//     }
// }
// cout<<"The second largest element in array is: "<<arr[secMax]<<endl;
// return 0;
//}


//    Find second largest element in array if all element are unique (Method-2)
#include<iostream>
#include<climits>
using namespace std;
int largestelement(int arr[]){
int max = INT_MIN;
int maxIndex = -1;
    for(int i=0; i<7; i++){
        if(arr[i]>max){
            max=arr[i];
            maxIndex = i;
        }
    }
    return max;
}
int main(){
int arr[] = {2,3,4,8,5,7,8};
int firstMax = largestelement(arr);
int secMax = INT_MIN;
for(int i=0; i<7; i++){
    if(arr[i]>secMax and arr[i]!=firstMax){
        secMax = arr[i];
    }
}
cout<<"The second largest element in the array is: "<<secMax<<endl;
return 0;
}


//         Find second largest element in array if  some elements are same


// #include<iostream>
// #include<climits>
// using namespace std;
// int largestelement(int arr[]){
// int max = INT_MIN;
// int maxIndex = -1;
//     for(int i=0; i<7; i++){
//         if(arr[i]>max){
//             max=arr[i];
//             maxIndex = i;
//         }
//     }
//     return max;
// }
// int main(){
// int arr[] = {2,3,4,8,5,7,8};
// int firstMax = largestelement(arr);
// for(int i=0; i<7; i++){
//     if(arr[i]==firstMax){
//         arr[i]=-1;
//     }
//     cout<<arr[i]<<" ";
// }
// cout<<endl;

// int secMax = INT_MIN;
// for(int i=0; i<7; i++){
//     if(arr[secMax]<arr[i]){
//         arr[secMax]=arr[i];
//     }
// }
// cout<<"The second largest element in array is: "<<arr[secMax]<<endl;
// return 0;
// }


