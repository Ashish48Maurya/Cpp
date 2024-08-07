#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int prefixEvaluation(string s){
    stack<int> st;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i]>='0' and s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+' :
               st.push(op1+op2);
                break;
            
            case '/' :
                st.push(op1/op2);
                break;

            case '*' :
                st.push(op1*op2);
                break;

            case '-' :
                st.push(op1-op2);
                break;
            }
        }
    }
    return st.top();
}
int main(){
    string s = "-5/63";
   cout<<prefixEvaluation(s)<<endl;
return 0;
}