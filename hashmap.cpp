#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> m;
    m[1] = "C++";
    m[2] = "Node-Js";
    m[3] = "HTML";
    m[4] = "CSS";
    m[5] = "JS";
    m[6] = "Mongo-DB";
    //In hashmap we can only be able to store unique element like we stored in set
    m[6] = "MONGO-DB";
    m.insert(make_pair(7,"React"));

    m.insert(make_pair(2,"NODE_JS"));  // Using this insert function if key is already present then it will return to next line else perform the given operation;
    // m[2] = "NODE_JS";    // This will change the value irrespective of whether key is already present or not

    // for(auto ele: m){
    //     cout<<ele.first<<"->"<<ele.second<<endl;
    // }

    map<int,string>::iterator itr;
    for(itr=m.begin(); itr!=m.end(); itr++){
        cout << itr->first << "->" << itr->second << endl;
    }
    return 0;
}