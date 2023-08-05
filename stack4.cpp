//College Wallah -> Stacks Lec-2;    find nearest Largest Element

//check output for 4 6 3 1 0 9 5 6 7 3
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//Using Vector
vector<int> nextGreatestElement(vector<int> &vec){
vector<int> temp(vec.size() , -1);
for(int i=0; i<vec.size(); i++){
    for(int j=i+1; j<vec.size(); j++){
        if(vec[i]<vec[j]){
            temp[i] = vec[j];
            break;
        }
    }
}
return temp;
}


//Using stack
vector<int> nge(vector<int> &vec){
    vector<int> temp(vec.size() , -1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<vec.size(); i++){
        while(!st.empty() and vec[st.top()]<vec[i] ){
            temp[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }
    return temp;
}

//Find Previous Greatest Element using Stack
vector<int> pge(vector<int> &arr){
    vector<int> ans(arr.size(),-1);
    reverse(arr.begin() , arr.end());
    stack<int> st;
    st.push(0);
    for(int i=1; i<arr.size(); i++){
        while(!st.empty() and arr[i]>arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

//nse -> nearest smaller element;
vector<int> nse(vector<int> &vec){   
    vector<int> ans(vec.size(),-1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<vec.size(); i++){
        while(!st.empty() and vec[st.top()]>vec[i]){
            ans[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}


//pse -> previous smaller element;
vector<int> pse(vector<int> &vec){
    vector<int> ans(vec.size(),-1);
    reverse(vec.begin(),vec.end());
    stack<int> st;
    st.push(0);
    for(int i=1; i<vec.size(); i++){
        while(!st.empty() and vec[st.top()]>vec[i]){
            ans[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int size;
    cout<<"Size of Array"<<endl;
    cin>>size;
    vector<int> vec;
    for(int i=0; i<size; i++){
        int ele;
        cin>>ele;
        vec.push_back(ele);
    }
    // vector<int> ans = nextGreatestElement(vec);
    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }

    //vector<int> ans = pge(arr);
    vector<int> ans = nge(vec);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}