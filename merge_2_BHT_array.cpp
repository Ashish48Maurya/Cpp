// #include<iostream>
// #include<vector>
// using namespace std;
// void heapify(vector<int> arr, int m , int i){
//         int root = i;
//         int leftNode = 2*i;
//         int rightNode = 2*i + 1;
//         if(leftNode<=m and arr[leftNode]>arr[root]){
//             // leftNode index > m(total no. of node) => overflow condition
//             root=leftNode;
//         }
//         if(rightNode<=m and arr[rightNode]>arr[root]){
//             root=rightNode;
//         }
//         if(root != i){
//             int temp = arr[i];
//             arr[i] = arr[root];
//             arr[root] = temp;
//             heapify(arr,m,root);
//         }
//     }

// vector<int> (vector<int>v1, vector<int>v2){
// vector<int> ans;
// for(auto element: v1){
// ans.push_back(v1[element]);
// }
// for(auto element: v2){
//     ans.push_back(v2[element]);
// }
// int size = ans.size();
// for(int i=size/2; i>0; i++){
// heapify(ans,8,1);
// }
// return ans;
// }
// int main(){
// vector<int> v1 = {8,3,6};
// vector<int> v2= {11,9,7,2,1};
// vector<int> Ans = vector<int>(v1,v2);
// for(auto element: Ans){
//     cout<<Ans[element]<<" ";
// }
// return 0;
// }