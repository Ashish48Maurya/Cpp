#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string ques = "Ashish.Likes.Programming";
    string ans = "";
    int size = ques.length();
    string temp;
    for(int i=size-1; i>=0; i--){
        if(ques[i]=='.'){
            reverse(temp.begin(), temp.end());
            temp.push_back('.');
            ans += temp;
            temp = "";
        }
        else{
            temp.push_back(ques[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans += temp;

    cout<<ans<<endl;
    return 0;
}