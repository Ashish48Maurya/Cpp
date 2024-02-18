#include<iostream>
#include<queue>
using namespace std;

void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,4,7,3,5,8,2};
    queue<int> q;
    int sizeOfWindow = 3;
    for(int i=0; i<sizeOfWindow-1; i++){
        q.push(arr[i]);
    }

    for(int i=sizeOfWindow-1; i<arr.size(); i++){
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    return 0;
}