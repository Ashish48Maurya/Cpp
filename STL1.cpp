//Standard Template Library
//Set of template class for implementing commonly used data structure and function   (e.g)=>Doublly LL
//List => Template class in STL for implementing doubly linked list;


#include<iostream>
#include<list>
using namespace std;
int main(){
list<int> l1 = {1,2,3,4};
auto itr = l1.begin();   // li.begin() - iterator for the first element;
//auto itr = l1.end();  // l1.end() - iterator pointing to the memory location after 4;
//itr is a pointer which stores adderess of a pointed member;
cout<<*itr<<endl;

// list.rbegin() - iterator for the first element in reverse iteration
auto rev_itr = l1.rbegin();
cout<<*rev_itr<<endl;

//advance(itr,n) - advances/moves the itr by n places
            //advance(itr,2);
            //cout<<*itr<<endl;

//traversal in LL using range-based loop
for(auto num: l1){
    cout<<num<<" ";
}cout<<endl;

//traversal in LL using iterators
for(auto itr = l1.begin(); itr!=l1.end(); itr++){
    cout<<*itr<<" ";
}cout<<endl;

//Reverse Traversal
for(auto itr = l1.rbegin(); itr!=l1.rend(); itr++){
    cout<<*itr<<" ";
}cout<<endl;

//Inserting element into the list  , list.insert(itr,value)=> insert value before the position of thhe itr
            //advance(itr,2);
            //l1.insert(itr,5);
            //for(auto num: l1){
            //    cout<<num<<" ";
            //}cout<<endl;


            //advance(itr,2);
            //l1.insert(itr,3,5);    //insert 5 3-times before itr,
            //for(auto num: l1){
            //    cout<<num<<" ";
            //}cout<<endl;

//deleting  element in LL   , list.erase(itr)=> delete element pointed by itr;
                            // list.erase(str_itr , end_itr)=> delete[str_itr,end_itr)
list<int> l2 = {1,2,1,2,3};

//There are lot of other member function of a list STL , explore them too
return 0;
}