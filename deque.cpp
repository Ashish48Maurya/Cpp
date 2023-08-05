#include <iostream>
#include <deque>
using namespace std;
deque<int> d;
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
   for(auto i:d){
    cout<<i<<" ";
   }
   cout<<endl;

   d.pop_back();
   for(auto i:d){
    cout<<i<<" ";
   }
   cout<<endl;

   d.pop_front();
   for(auto i:d){
    cout<<i<<" ";
   }
    return 0;
}