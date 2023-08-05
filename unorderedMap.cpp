#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
unordered_map<int,string> m;
m[1] = "Java";
m[2] = "C++";
m[3] = "Js";
for(auto itr:m){
    cout<<itr.first<<"->"<<itr.second<<endl;
}
return 0;
}