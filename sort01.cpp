// #include <iostream>
// #include <vector>
// using namespace std;
// void sort01Array(vector<int> &v)
// {
//     int zeroesCount = 0;
//     for (auto element : v)
//     {
//         if (v[element])
//         {
//             zeroesCount++;
//         }
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (zeroesCount > i)
//         {
//             v[i] = 0;
//         }
//         else
//         {
//             v[i] = 1;
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         int ele;
//         cin >> ele;
//         v.push_back(ele);
//     }
//     sort01Array(v);
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     return 0;
// }



#include<iostream>
#include<vector>
using namespace std;
void sort01Array(vector<int> &v){
    int start = 0;
    int end = v.size()-1;
    while(end!=start){
    if(v[start]==1 and v[end]==0){
        swap(v[start],v[end]);
        start++;
        end--;
    }
    else if(v[start]==0){
        start++;
    }
    else{
        end--;
    }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    sort01Array(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}