#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string sortString(string value){
vector<int> alpha(26,0);
for(int i=0; i<value.size(); i++){
    alpha[value[i]-'a']++;
}
string ans = "";
for(int i=0; i<26; i++){
    char c = 'a'+i;
    while(alpha[i]){
        ans+=c;
        alpha[i]--;
    }
}
return ans;
}

string sortVowel(string value){
    string ans = "";
    vector<char> upperCase(26,0);
    vector<char> lowerCase(26,0);
    for(int i=0; i<value.size(); i++){
        char c = value[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            lowerCase[value[i] - 'a']++;
            value[i] = '#';
        }
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            upperCase[value[i] - 'A']++;
            value[i] = '#';
        }  
    }
    for(int i=0; i<26; i++){
        char c = 'A'+i;
            while(upperCase[i]){
                ans+=c;
                upperCase[i]--;
            }
    }
    for(int i=0; i<26; i++){
        char c = 'a'+i;
            while(lowerCase[i]){
                ans+=c;
                lowerCase[i]--;
            }
    }
    
    int first = 0 , second = 0; //first is pointing to ans strinig and second is pointing to value string;
    while(first<ans.size()){
        if(value[second]=='#'){
            value[second++] = ans[first++];
        }
        else{
        second++;
        }
    }
    return value;
}

string addNumbers(string num1, string num2){
    int carry = 0;
    int idx1 = num1.size()-1;
    int idx2 = num2.size()-1;
    string ans = "";
    while(idx2>=0){
        char sum = (num1[idx1--]-'0') + (num2[idx2--]-'0') + carry;
        carry = sum/10;
        char c = '0'+sum%10;
        ans += c;
    }
    while(idx1>=0){
        char sum = (num1[idx1--]-'0')+ carry;
        carry = sum/10;
        char c = '0'+sum%10;
        ans += c;
    }
    if(carry){
        ans += carry+'0';
    }
    reverse(ans.begin(),ans.end());
    return ans;

}


int num(char c){
    if(c=='I'){
        return 1;
    }
    if(c=='V'){
        return 5;
    }
    if(c=='X'){
        return 10;
    }
    if(c=='L'){
        return 50;
    }
    if(c=='C'){
        return 100;
    }
    if(c=='D'){
        return 500;
    }
    if(c=='M'){
        return 1000;
    }
}

int convertRomanToDigit(string value){
    int ans = 0;
    int index = 0;
    while(index < value.size()-1){
        char f = value[index];
        char s = value[index+1];
        if (num(s) > num(f)) {
            ans -= num(f);
        } else {
            ans += num(f);
        }
        index++;
    }
    ans += num(value[value.size()-1]);
    return ans;
}

int largestSubstringWithUniqueChars(string q){
    vector<bool> storeChar(256,0);
    int first=0,second=0,length=0;
    while(second<q.size()){
        while(storeChar[q[second]]){
            storeChar[q[first++]] = 0;
        }
        storeChar[q[second++]] = 1;
        length = max(length,second-first);
    }
    return length;
}


int main(){

    // int num = '2'-'0';
    // cout<<num<<endl;

    // string value = "ashish";
    // string ans = sortString(value);
    // cout<<ans<<endl;

    // string value = "SeItriniAagUoE";
    // string ans = sortVowel(value);
    // cout<<ans<<endl;

    // string num1 = "95361";
    // string num2 = "7112";
    // string ans = addNumbers(num1,num2);
    // cout<<ans<<endl;

    //Logic: if value of string present at index+1 is greater than the value of char present at index(th position) than take value of char present at index position as negative
    // string Roman1 = "LCXMVIV";
    // string Roman2 = "IV"; //For Testing Purpose, ans must be 4
    // int ans = convertRomanToDigit(Roman1);
    // cout<<ans<<endl;

    //I have used 256 because given string may contain special Characters , Capital and Small Alphabets.
    string question = "abcae";
    int ans = largestSubstringWithUniqueChars(question);
    cout<<ans<<endl;

    
    return 0;
}