#define MOD 100000007
#define ll long long
#include<bits/stdc++.h>
using namespace std;


                                    //Rabin Karp
ll hashValue(string str2, int p, int m) {
    ll ans = 0, factor = 1;
    for (int i = m - 1; i >= 0; i--) {
        ans = (ans + ((str2[i] - 'a') * factor) % MOD) % MOD;
        factor = (factor * p) % MOD;
    }
    return ans;
}

int findIdx2(string str1, string str2, int p) {
    int n = str1.size();
    int m = str2.size();
    if (m > n) return -1;

    ll maxSize = 1;
    for (int i = 0; i < m; i++) {
        maxSize = (maxSize * p) % MOD;
    }

    ll hashStr2 = hashValue(str2, p, m), hashStr1 = 0;
    for (int i = 0; i <= n - m; i++) {
        if (i == 0) {
            hashStr1 = hashValue(str1.substr(0, m), p, m);
        } else {
            hashStr1 = (hashStr1 * p) % MOD;
            hashStr1 = (hashStr1 - (str1[i - 1] - 'a') * maxSize) % MOD;
            hashStr1 = (hashStr1 + (str1[i + m - 1] - 'a')) % MOD;
        }

        if (hashStr1 == hashStr2) {
            int j;
            for (j = 0; j < m; j++) {
                if (str2[j] != str1[i + j]) {
                    break;
                }
            }
            if (j == m) return i;
        }
    }
    return -1;
}

int main(){
    string str1 = "aabaddabdabad";
    string str2 = "abad";
    // cout<<findIdx(str1,str2);
    // cout<<findIdx1(str1,str2);
    int primeNo;
    cout<<"Enter Any Number Greater than 25: ";
    cin>>primeNo;
    cout<<findIdx2(str1,str2, primeNo);
    return 0;
}