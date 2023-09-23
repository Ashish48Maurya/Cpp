#include <iostream>
#include <stack>
#include <ctype.h>
using namespace std;
int postfixEvaluation(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s = "46+2/5*7+";
    cout << postfixEvaluation(s) << endl;
    return 0;
}