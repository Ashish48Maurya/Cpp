//No. of Characters need to be added in the given string to make it palindrome
#include<iostream>
#include<vector>
using namespace std;
int computeLPS(string str){
    int n = str.size();
    vector<int> lps(str.size(), 0);
    int prefix = 0;
    int suffix = 1;
    while(suffix < n){
        if(str[prefix] == str[suffix]){
            lps[suffix] = prefix+1;
            prefix++;
            suffix++;
        }
        else{
            if(prefix != 0){
                prefix = lps[prefix-1];
            }
            else{
                suffix++;
            }
        }
    }
    return lps[n-1];    //this will return length of Largest prefix which is equal to Suffix;
}

int main(){
    string str = "roaorta";
    string str2 = "";
    for(int i=str.size()-1; i>=0; i--){
        str2 += str[i];
    }
    string str3 = str+'$'+str2;
    int noOfCharsRequire = str.size() - computeLPS(str3);
    string str4 = "";
    for(int i=computeLPS(str3); i<str.size(); i++){
        str4 += str[i];
    }

    string str5 = "";
    for(int i=str4.size()-1; i>=0; i--){
        str5 += str4[i];
    }
    cout<<"Palindrome String: "<<str5+str<<endl;
    return 0;
}