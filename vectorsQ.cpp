#include <iostream>
#include <vector>
using namespace std;

void display(vector<char> &vec)
{
    for (auto element : vec)
    {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    int T;
    cout << "Enter Number of Cases you want ";
    cin >> T;
    while (T > 0)
    {
        int N;
        cout << "How Many Characters You want to push_back to the array";
        cin >> N;
        vector<char> vec;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            vec.push_back(ch);
        }

        for (int i = 0; i < N % 26; i++)
        {
            vec.push_back(*(vec.begin()));
            vec.erase(vec.begin());
        }

        display(vec);
        T--;
    }
    return 0;
}