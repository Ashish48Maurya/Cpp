//Stack Implementaion by Array;

#include<iostream>
using namespace std;
class Stack{
  int capacity;
  int *arr;
  int top;

  public:
  Stack(int size){
    capacity = size;
    arr = new int[size];
    top = -1;
  }

  void push(int element){
    if(top==(capacity-1)){
        cout<<"Push Operation impossible - Stack Overflow"<<endl;
        return;
    }
    else{
        top++;
        arr[top] = element;
    }
  }

  void pop(){
    if(top==-1){
        cout<<"Nothing to pop Stack is Empty"<<endl;
    }
    else{
        top--;
    }
  }

  int topEle(){
    if(top==-1){
        cout<<"STack is Empty"<<endl;
        return -1;
    }
    else{
        return arr[top];
    }
  }


  void isEmpty(){
    if(top==-1){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    cout<<"Stack is Not Empty"<<endl;
  }

  bool isFull(){
    if(top == capacity-1){
      return true;
    }
    
      return false;
  }

};

int main(){

Stack st(5);
st.push(1);
st.push(2);
cout<<st.topEle()<<endl;
st.push(3);
st.push(4);
cout<<st.isFull()<<endl;
cout<<st.topEle()<<endl;
st.pop();
cout<<st.topEle()<<endl;
st.push(5);
st.push(6);
cout<<st.isFull()<<endl;
return 0;
}