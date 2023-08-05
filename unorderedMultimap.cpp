#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_multimap<int, string> m;
    m.insert(make_pair(1, "C++"));
    m.insert(make_pair(4, "Css"));
    m.insert(make_pair(5, "Mongo-DB"));
    m.insert(make_pair(2, "Java"));
    m.insert(make_pair(3, "NodeJs"));
    m.insert(make_pair(1, "Js"));

    for(auto ele:m){
        cout<<ele.first<<"->"<<ele.second<<endl;
    }
    

    return 0;
}
