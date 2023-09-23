//Given a array of strings you have to sort this array lexicographically using selection sort
#include<iostream>
#include<cstring>
using namespace std;

void selectionSort(char fruit[][60] , int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(fruit[min_idx] , fruit[j]) > 0){
                min_idx=j;
            }
        }

        if(i!=min_idx){
            swap(fruit[min_idx] , fruit[i]);
        }
    }

    for(int i=0; i<n; i++){
        cout<<fruit[i]<<" ";
    }
}

int main(){
    char fruit[][60] = {"Grapes" , "Kiwi" , "Apple", "Mango"};
    int n = 4;
    selectionSort(fruit, n);
    return 0;
}