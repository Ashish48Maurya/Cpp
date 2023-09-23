#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size){
    vector<vector<float>> bucket(size, vector<float>());

    float max_ele = arr[0];
    float min_ele = arr[0];

    // Find the maximum and minimum elements in the array
    for(int i=0; i<size; i++){
        max_ele = max(max_ele, arr[i]);
        min_ele = min(min_ele, arr[i]); // Use min() here to find the minimum
    }

    float range = (max_ele - min_ele) / size;

    // Fill the buckets
    for(int i=0; i<size; i++){
        int index = (arr[i] - min_ele) / range;
        if (arr[i] == max_ele) {
            bucket[size - 1].push_back(arr[i]); // Place the maximum element in the last bucket
        }
        else {
            bucket[index].push_back(arr[i]);
        }
    }

    // Sort each bucket
    for(int i=0; i<size; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }

    int k = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<bucket[i].size(); j++){
           arr[k++] = bucket[i][j];
        }
    }
    
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    float arr[] = {1.13, 6.45, 2.12, 4.89, 9.75, 10.63, 0.85, 7.39};
    int size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, size);
    return 0;
}
