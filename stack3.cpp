//Reverse Word Using Stack
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s = "Ashish";
    //string s = "Hello";
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        st.push(ch);
    }

    // string ans = "";
    // while(!st.empty()){
    //     ans += st.top();
    //     st.pop();
    // }
    // cout<<"Answer is: "<<ans<<endl;

                    //OR//
    
    while(!st.empty()){
        char ch = st.top();
        st.pop();
        cout<<ch<<endl;
    }
    return 0;
}



//Reverse sentence using stack
#include<iostream>
using namespace std;
#include<stack>
void reversSentence(string S){
    stack<string> st;
   for(int i=0; i<S.length(); i++){
    string word = "";
    while(S[i]!=' ' and i<S.length()){
        word += S[i];
        i++;
    }
     st.push(word);
   }
   while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
   }
   cout<<endl;
}
int main(){
    string S = "Hii, how are you?";
    reversSentence(S);
return 0;
}



//Copy Satck
#include<iostream>
#include<stack>
using namespace std;
stack<int> copyStack(stack<int> st){
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }

    stack<int> result;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }

    return result;

}

//Recursive way
void f(stack<int> &st,stack<int> &ans){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    f(st,ans);
    ans.push(curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    stack<int> ans = copyStack(st);
    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }

    cout<<endl;

    stack<int> ans1;
    f(st,ans1);
    while(!ans1.empty()){
        cout<<ans1.top()<<endl;
        ans1.pop();
    }
    return 0;
}



//Insert Element at the bottom of stack
#include<iostream>
#include<stack>
using namespace std;

stack<int> insert_at_bottom(stack<int> &st , int ele){
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    stack<int> ans;
    ans.push(ele);
    while(!temp.empty()){
        ans.push(temp.top());
        temp.pop();
    }
    return ans;
}

//Recursive Way
void insertAtBottom(stack<int> &st , int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(curr);
}

int main(){
stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
// insertAtBottom(st,100);
// while(!st.empty()){
//     cout<<st.top()<<endl;
//     st.pop();
// }

cout<<endl;

stack<int> ans = insert_at_bottom(st,100);
while(!ans.empty()){
    cout<<ans.top()<<endl;
    ans.pop();
}
return 0;
}



//insert element at a given index of a stack
#include<iostream>
#include<stack>
using namespace std;
void insertAtIndex(stack<int> &st , int ele , int idx, int n){

if(idx>n){
cout<<"Insertion Not Possible"<<endl;
return;
}

if(st.size()==idx-1){
    st.push(ele);
    return;
}
int curr = st.top();
st.pop();
insertAtIndex(st,ele,idx,n);
st.push(curr);
}

int main(){
stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
insertAtIndex(st,100,4,st.size());
while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
}
return 0;
}