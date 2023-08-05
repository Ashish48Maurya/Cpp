// #include<iostream>
// using namespace std;
// void reverse(string str){
//     if(str.length()==0){
//         return ;
//     }
//     string rest = str.substr(1);
//     reverse(rest);
//     printf("%c",str[0]);
// }
// int main(){
// string str;
// cin>>str;
// cout<<"Before Reversing: "<<str<<endl;
// cout<<"After Reversing: ";
// reverse(str);
// return 0;
// }

#include<iostream>
using namespace std;
void reverse(string str , int length){
    int i = 0;
    int j = length-1;
    while(j>=i){
        swap(str[i],str[j]);
        i++;
        j--;
    }
    cout<<str<<endl;
}
int main(){
string str;
cin>>str;
int length = str.length();
reverse(str,length);
return 0;
}