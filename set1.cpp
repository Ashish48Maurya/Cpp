// Given a 2 vector find the sum of elements common in both the vectors
// vector-1 may contains similar elements but vector-2 only contains unique element
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;
    vector<int> v2;
    set<int> st;
    int result = 0;

    cout<<"Enter No. of Elements wants in Vector: ";
    int n;
    cin>>n;

    cout<<"Enter Vector-1 Elements: "<<endl;
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        v1.push_back(ele);
        st.insert(ele);
    }cout<<endl;

    cout<<"Enter Vector-2 Elements: "<<endl;
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        v2.push_back(ele);
    }cout<<endl;

    for(auto res: v2){
        if(st.find(res)!=st.end()){
            result += res;
        }
    }

    cout<<"Answer: "<<result<<endl;
    return 0;
}