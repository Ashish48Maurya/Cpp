#include<iostream>
#include<queue>
using namespace std;
int main(){
priority_queue<int> p;
p.push(1);
p.push(10);
p.push(5);
p.push(7);
cout<<"Top element is: "<<p.top()<<endl;
p.pop();
cout<<"Top element is: "<<p.top()<<endl;

priority_queue<int , vector<int> ,greater<int>> minheap;
minheap.push(1);
minheap.push(10);
minheap.push(5);
minheap.push(7);
cout<<"Top element is: "<<minheap.top()<<endl;
minheap.pop();
cout<<"Top element is: "<<minheap.top()<<endl;
return 0;
}