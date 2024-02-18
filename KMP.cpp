// Method-1 : check whether string2 is present in string1 if it is so than return the index
#include <iostream>
using namespace std;
int main()
{
    string str1 = "ababcbcabcd";
    string str2 = "abcd";
    int n = str1.size();
    int m = str2.size();
    for (int i = 0; i <= n - m; i++)
    {
        int first = i;
        int second = 0;
        while (m > second)
        {
            if (str1[first] != str2[second])
            {
                break;
            }
            else
            {
                first++, second++;
            }
        }
        if(second==m){
            cout << "String found at index: " << i << endl;
            return i;
        }
    }
    //if string2 is not present in string1
    cout<<"String is Not Present"<<endl;
    return -1;
}