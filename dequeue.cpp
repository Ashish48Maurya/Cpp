#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(10);
    dq.push_back(5);
    dq.push_front(23);
    dq.push_front(3);
    dq.push_front(9);

    for(auto ele: dq){
        cout<<ele<<" ";
    }cout<<endl;

    dq.pop_back();
    for(auto ele: dq){
        cout<<ele<<" ";
    }cout<<endl;

    dq.front();
    dq.pop_front();
    for(auto ele: dq){
        cout<<ele<<" ";
    }cout<<endl;
    return 0;
}