// #include<iostream>
// using namespace std;

// int partition(int arr[],int first,int last){
//     int pivot = arr[last];
//     int i = first-1;
//     int j = first;
//     for(; j<last; j++){
//         if(arr[j]<pivot){
//           i++;
//           swap(arr[j],arr[i]);  
//         }
//     }
//     swap(arr[last],arr[i+1]);
//     return i+1; //---> Because Pivot Element is present at i+1;
// }

// void quickSort(int arr[],int first,int last){
//     if(first>=last){
//         return;
//     }
//     int pi = partition(arr,first,last); //------>Using this we will get our pivot/partition point
//     quickSort(arr,first,pi-1);
//     quickSort(arr,pi+1,last);
// }

// int main(){
//     int arr[] = {9,0,6,8,2,1};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     quickSort(arr,0,n-1);
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


                            //OR//

#include<iostream>
#include<vector>
using namespace std;

int partitionEle(vector<int> &v , int first , int last){
    int pivot = v[last];
    int i = first-1;
    for(int j=first ; j<last; j++){
        if(v[j]<pivot){
            i++;
            swap(v[j],v[i]);
        }
    }
    swap(v[i+1],v[last]);
    return i+1;
}

void quickSort(vector<int> &v , int first, int last){
    if(first>=last){ return; }
    int pi = partitionEle(v,first,last);
    quickSort(v,first,pi-1);
    quickSort(v,pi+1,last);
}

int main(){
    vector<int> vec = {9,0,6,8,2,1};
    quickSort(vec,0,vec.size()-1);
    for(auto ele: vec){
        cout<<ele<<" ";
    }
    return 0;
}