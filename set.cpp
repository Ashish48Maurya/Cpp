#include<iostream>
#include<set>
using namespace std;
int main(){
set<int> st;

st.insert(1);
st.insert(2);
st.insert(3);
for(auto val: st){
    cout<<val<<" ";
}cout<<endl;
cout<<st.size()<<endl;

st.insert(2);
cout<<st.size()<<endl;

cout<<st.count(2)<<endl; //returns 1 if present else return false;


st.insert(5);
st.insert(6);
st.insert(7);
st.erase(4);
for(auto val: st){
    cout<<val<<" ";
}cout<<endl;


auto itr1 = st.begin(); //point to 2nd position
itr1++; 

auto itr2 = st.begin(); //point to 4th position
advance(itr2,3); //increments itr2 by 3 steps;

st.erase(itr1,itr2); //will erase including 2nd position excluding 4th position
for(auto val: st){
    cout<<val<<" ";
}cout<<endl;

set<int> st2 = {1,2,3,45,6,7,0};
set<int>::iterator itr;
for(itr=st2.begin(); itr!=st2.end(); itr++){
    cout<<*itr<<" ";
}
//st2.begin() -> points to 1st element of the set
//st2.end() -> points to the position after last element (after 0 in this case);

return 0;
}