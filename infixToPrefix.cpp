#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int prec(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else{
        return -1;
    }
}
string infixToPrefix(string str){
    reverse(str.begin(),str.end());
    stack<char> st;
    string res;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='a' and str[i]<='z'){
            res+=str[i];
        }

        else if(str[i]==')'){
            st.push(str[i]);
        }

        else if(str[i]=='('){
            while(!st.empty() and st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() and (prec(str[i])<prec(st.top()))){
                res+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(str.begin(),str.end());
    return res;
}
int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)");
    return 0;
}