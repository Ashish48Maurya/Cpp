#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> q = {4, 7, 0, 5, 2, 6, 1, 3}; // 0 1 2 3 4 5 6 7
    sort(q.begin(), q.end());

    int ele;
    cout << "Enter Element Which you want to Search: ";
    cin >> ele;
    for (int i = 0; i < q.size() - 1; i++)
    {
        int x = q[i];

        int first = i + 1;
        int last = q.size() - 1;
        // Kind of Binary Search
        while (last > first)
        {
            if (first + last == ele - x)
            {
                cout << i <<" "<< first <<" "<< last << endl;
                break;
            }
            else if (first + last > ele - x)
            {
                last--;
            }
            else
            {
                first++;
            }
        }
    }

    return 0;
}