#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,3,4,1,2,5};
    int size = 6;
    int target = 5;
    int pairs = 0;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] + arr[j] == target){
                pairs++;
            }
        }
    }

    cout<<"Total No. of Pairs: "<<pairs<<endl;
    // printf("Total No. of pairs: %d" , pairs);
    return 0;
}