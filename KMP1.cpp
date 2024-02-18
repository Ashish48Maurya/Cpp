#include <iostream>
#include <vector>
#include <string>

using namespace std;

int computeLPS(const string& str) {
    int n = str.size();
    vector<int> lps(n, 0);

    int prefix = 0;
    int suffix = 1;

    while (suffix < n) {
        if (str[prefix] == str[suffix]) {
            lps[suffix] = prefix+1;
            prefix++;
            suffix++;
        } else {
            if (prefix != 0) {
                prefix = lps[prefix - 1];
            } else {
                suffix++;
            }
        }
    }

    return lps[n-1];
}

int main() {
    string str = "abab";
    int ans = computeLPS(str);

    cout<<ans<<endl;

    return 0;
}
