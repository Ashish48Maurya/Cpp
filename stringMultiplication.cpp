#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<string>> calc;
    string str1 = "279";
    string str2 = "123";
    for(int i=str2.size()-1; i>=0; i--){
        string ans = "";
        vector<string> calculated;
        int index = 0;
        int num2 = str2[i]-'0';
        for(int j=str1.size()-1; j>=0; j--){
            int num1 = str1[i]-'0';
            int ans = num1*num2 + index;
            index = ans/10;
            ans += ans%10 + '0';
        }
        
    }
    return 0;
}