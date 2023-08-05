#include<iostream>
#include<list>
using namespace std;

void display(list<int> &ls){
    list<int>::iterator itr;
    for (itr = ls.begin(); itr != ls.end(); itr++) {
        cout << *itr << " ";
    }
    cout<<endl;
}

int main(){
    list<int> ls1;
    cout<<"ls1: ";
    ls1.push_back(1);
    ls1.push_back(2);
    ls1.push_back(3);
    display(ls1);

    list<int> ls2;
    cout<<"ls2: ";
    ls2.push_back(4);
    ls2.push_back(5);
    ls2.push_back(6);
    display(ls2);
    
    ls1.merge(ls2);
    cout<<"ls1 after merging with ls2 : ";
    display(ls1);

    ls1.reverse();
    cout<<"Reverse of ls1 : ";
    display(ls1);

    list<int> ls3;
    ls3.push_back(9);
    ls3.push_back(11);
    ls3.push_back(0);
    ls3.push_back(15);
    cout<<"ls3: ";
    display(ls3);
    
    ls3.sort();
    cout<<"ls3 after Sorting: ";
    display(ls3);
    
    return 0;
}
