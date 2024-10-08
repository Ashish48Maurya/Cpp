#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size){
    vector<vector<float>> bucket(size,vector<float> ());

    for(int i=0; i<size; i++){
        int index = arr[i]*size;
        bucket[index].push_back(arr[i]);
    }

    for(int i=0; i<size; i++){
        sort(bucket[i].begin() , bucket[i].end());
    }

    int k = 0;
    for(int i=0; i<bucket.size(); i++){
        for(int j=0; j<bucket[i].size(); j++){
           arr[k++] = bucket[i][j];
        }
    }
    
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    float arr[] = {0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39};
    int size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,size);
    return 0;
}