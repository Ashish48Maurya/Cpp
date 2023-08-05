#include<iostream>
using namespace std;
int main(){
    
// start:{
// cout<<"Hello Ashish"<<endl;
// }
// goto start;

for(int i=0; i<5; i++){
    cout<<i<<endl;
    for(int j=0; j<5; j++){
        cout<<j<<" -Ashish"<<endl;
    }
    goto end;
}
end:
return 0;
}