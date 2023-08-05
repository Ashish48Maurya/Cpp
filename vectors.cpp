#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int main(){
// vector<int> v;
// v.push_back(1);
// v.push_back(2);
// v.push_back(3);

// for(int i=0; i<v.size(); i++){
//     cout<<v[i]<<endl;
// }
// return 0;
// }


// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     vector<int>::iterator it;
//     for(it=v.begin(); it != v.end(); it++){
//         cout<<*it<<endl;
//     }
//     return 0;
// }

// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     for (auto i:v){
//         cout<<i<<endl;
//     }
//     return 0;
// }


// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     v.pop_back();
//      for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<endl;
//     }
//     return 0;
// }


// int main(){
// vector<int> v(2,50);
// for(int i=0; i<v.size(); i++){        // 50  50  print karegaa
// cout<<v[i]<<endl;
// }
// return 0;
// }

// int main(){  
//     vector<int> v1;
//     v1.push_back(1);
//     v1.push_back(10);
//     v1.push_back(100);

//     cout<<" ";

//     vector<int>v2;
//     v2.push_back(2);
//     v2.push_back(20);
//     v2.push_back(200);
//     v2.push_back(2000);

//     swap(v1,v2);
//     for(auto element : v1){
//         cout<<element<<endl;
//     }
//     for(auto element : v2){
//         cout<<element<<endl;
//     }
//     return 0;
// }

int main(){
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);

for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
}
cout<<endl;

v.insert(v.begin()+2 , 6);

for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
}cout<<endl;

v.insert(v.end()-2 , 7);

for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
}cout<<endl;

v.erase(v.begin()+2);

for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
}cout<<endl;

v.erase(v.end()-2);

for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
}cout<<endl;


cout<<"Printing vec Vector"<<endl;
vector<int> vec = {1,2,3,4,5,9,7};


for(auto itr1: vec){
    cout<<itr1<<" ";
}cout<<endl;

vector<int>::iterator itr2 = vec.begin();
advance(itr2,2);
vec.erase(itr2);
for(itr2=vec.begin(); itr2!=vec.end(); itr2++){
    cout<<*itr2<<" ";
}cout<<endl;

vector<int>::iterator itr3;
itr3 = find(vec.begin(),vec.end(),9);
if(itr3!=vec.end()){
    cout<<"Element is present in a vector at position: "<<itr3-vec.begin()<<endl;
}
else{
    cout<<"Element is not present in a vector"<<endl;
}

return 0;
}

// 2-D array
//vector<vector<int>> vec(n,vector<int>(m));
// har row me ekh vector rakha huaa hai of size m;
// n-> row  &   m->column;