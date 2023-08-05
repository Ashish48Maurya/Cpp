//Given an array of the fruit; you are supposed to sort it in lexicographical order using the selection sort
// Input: ["papaya","lime","watermelon","apple","mango","kiwi"]
//Output: ["apple","kiwi","lime","mango","papaya","watermelon"]
//Application of Selection Sort
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    //cout<<strcmp("papaya","lime");   ---> +ve value
    //cout<<strcmp("lime","papaya");   ---> -ve value  ---> arr[2]>arr[1]
    //cout<<strcmp("lime","lime");     ---> neutral value
    char fruit[][60] = {"papaya","lime","watermelon","apple","mango","kiwi"};
    int n = sizeof(fruit)/sizeof(fruit[0]);
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(fruit[min_idx],fruit[j])>0){
                min_idx=j;
            }
        }
        if(i!=min_idx){
            swap(fruit[i],fruit[min_idx]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<fruit[i]<<" ";
    }
    return 0;
}