//Histogram Problem
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
vector<int> nse(vector<int> vec){   
    vector<int> ans(vec.size(),-1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<vec.size(); i++){
        while(!st.empty() and vec[st.top()]>vec[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> pse(vector<int> vec){
    vector<int> ans(vec.size(),-1);
    reverse(vec.begin(),vec.end());
    stack<int> st;
    st.push(0);
    for(int i=1; i<vec.size(); i++){
        while(!st.empty() and vec[st.top()]>vec[i]){
            ans[st.top()] = vec.size()-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
vector<int> vec;
for(int i=0; i<13; i++){
    int x;
    cin>>x;
    vec.push_back(x);
}
vector<int> ans1 = nse(vec);
vector<int> ans2 = pse(vec);

int ans = INT_MIN;
for(int i=0; i<vec.size(); i++){
    int val = (ans1[i]-ans2[i]-1)*vec[i];
    ans = max(ans,val);
}
cout<<ans;
return 0;
}