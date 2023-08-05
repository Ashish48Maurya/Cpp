#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> v1, vector<int> v2 ,vector<int> v3){
    int i = 0, j = 0, k = 0;
    while(i<v1.size() and j<v2.size()){
        if(v1[i]>v2[j]){
            v3.push_back(v2[j]);
            j++;
        }
        else{
            v3.push_back(v1[i]);
            i++;
        }
    }
    while(i<v1.size()){
        v3.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
       v3.push_back(v2[j]);
        j++;
    }
    for(int i=0; i<v3.size(); i++){
    cout<<v3[i]<<" ";
    }
}
int main(){
vector<int> v1 = {1,2,3,10,14};
vector<int> v2 = {4,5};
vector<int> v3;
merge(v1,v2,v3);
return 0;
}