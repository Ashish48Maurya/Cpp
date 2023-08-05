// Check hash working

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
int arr[5] = {1,2,4,1,1};
unordered_map<int,int> um;
for(int i=0; i<5; i++){
um[arr[i]]++;
}
unordered_map<int, int> :: iterator it = um.begin();
while(it != um.end()){
cout<<it->first<<" "<<it->second<<endl;
it++;
}
return 0;
}