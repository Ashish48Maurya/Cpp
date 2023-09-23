#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void countSort(vector<int> &v , int pos){
    int n = v.size();
    vector<int> freq(10,0);
    
    //Frequency Array
    for(int i=0; i<n; i++){
        freq[(v[i]/pos)%10]++;
    }

    //Cummulative Frequency
    for(int i=1; i<10; i++){
        freq[i] += freq[i-1];
    }

    //Ans Array
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        ans[--freq[(v[i]/pos)%10]] = v[i];
    }

    for(int i=0; i<n; i++){
        v[i]=ans[i];
    }
}

void radixSort(vector<int> &v){
    int max_ele = INT_MIN;
    for(auto ele: v){
        if(ele>max_ele){
            max_ele = ele;
        }
    }

    for(int pos=1; max_ele/pos > 0; pos = pos*10){
        countSort(v,pos);
    }
}

int main(){
    vector<int> vec = {1,502,809,6,304,0};
    radixSort(vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}