#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxOnesRow(vector<vector<int>> &v) {
    int maxOneInRow = INT_MIN;
    int rowNo = -1;
    int noOfColumns = v[0].size(); // Because 2-D array
    for (int i = 0; i < v.size(); i++) {
        int numberOfOnes = 0; 
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 1) {
                numberOfOnes = noOfColumns - j;
                if (numberOfOnes > maxOneInRow) {
                    maxOneInRow = numberOfOnes;
                    rowNo = i;
                }
                break;
            }
        }
    }
    return rowNo;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int ans = maxOnesRow(vec);
    cout << ans << endl;
    return 0;
}
