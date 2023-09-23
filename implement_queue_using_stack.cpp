//Push Efficient
#include <iostream>
#include <stack>
using namespace std;

class queueUsingStack {
    stack<int> st;

public:
    queueUsingStack() {}

    void push(int val) {
        st.push(val);
    }


    stack<int> temp;
    void pop() {
        // Transfer elements from st to temp, except the top element
        while (st.size() > 1) {
            temp.push(st.top());
            st.pop();
        }
        
        // Pop the top element (dequeue)
            st.pop();

        // Move elements back from temp to st
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }

    int peek(){
        if(st.empty()){
            return -1;
        }
        while (st.size() > 1) {
            temp.push(st.top());
            st.pop();
        }
        
        int ans = st.top();
        st.pop();

        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        return ans;  
    }

    bool empty(){
        return st.empty();
    }
};

int main() {
    queueUsingStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    while(!q.empty()){
        cout<<q.peek()<<" ";
    }
    return 0;
}
