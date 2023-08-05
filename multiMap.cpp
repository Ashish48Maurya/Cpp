#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> m;
    m.insert(make_pair(1, "C++"));
    m.insert(make_pair(2, "Java"));
    m.insert(make_pair(3, "NodeJs"));
    m.insert(make_pair(1, "Js"));

    multimap<int, string>::iterator itr = m.begin();
    advance(itr, 3);
    cout << itr->first << "->" << itr->second << endl;

    return 0;
}
