#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    vector<int> q = {12, -1, -7, 8, -15, 30, 16, 28};
    queue<int> qu;
    vector<int> ans;
    int sizeOfWindow = 3;

    for (int i = 0; i < sizeOfWindow - 1; i++)
    {
        if (q[i] < 0)
        {
            qu.push(i);
        }
    }

    for (int i = sizeOfWindow - 1; i < q.size(); i++)
    {
        // Enter the Element in the queue if it is negative
        if (q[i] < 0)
        {
            qu.push(i);
        }

        // Display the first negative element from the queue which lies in the window
        if (qu.empty())
        {
            ans.push_back(0);
        }
        else
        {
            if (qu.front() <= i - sizeOfWindow)
            {
                qu.pop();
            }
            if (qu.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q[qu.front()]);
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << ",";
    }
    return 0;
}
