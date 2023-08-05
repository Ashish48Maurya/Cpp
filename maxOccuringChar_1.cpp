#include<iostream>
#include<unordered_map>
using namespace std;
char maxOccur(char arr[]){
unordered_map<char,int> um;
for(int i=0; i<8; i++){
um[arr[i]]++;
}
int maxI = -1; int ans = 0;
for(auto element: um){
    if(element.second>maxI){
        maxI = element.second;
        ans = element.first;
    }
}
return ans;
}
int main(){
char arr[] = {'a','d','e','f','a','a','g','d'};
cout<<endl;
cout<<"Maximum Occuring element in array is: "<<maxOccur(arr)<<endl;
return 0;
}