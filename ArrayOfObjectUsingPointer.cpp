// See 2D_Array before stating this
#include<iostream>
using namespace std;
class ShopItem{
    int Id;
    float Price;
public:
    void setdata(int p, float q){
        Id = p;
        Price = q;
    }
    void getdata(){
        cout<<"Code of this item is "<<Id<<endl;
        cout<<"Price of this item is "<<Price<<endl;
    }
};
int main(){
int p;
float q;
ShopItem *b = new ShopItem[3];    // array form kiye
ShopItem *bTemp = b;
for(int i=0; i<3; i++){
    cout<<"Enter Id and Price of item "<<i+1;
    cin>>p>>q;
    b->setdata(p,q);
    b++;
}
for(int i=0; i<3; i++){
    cout<<"Item number: "<<i+1<<endl;
    bTemp->getdata();
    bTemp++;
}
return 0;
}
/*
2 types ke memory hota hai stack and heap
stack chota storage wala hota hai heap bada storage wala hota hai
code me agar array bana rahe hai toh wo stack wale slot ka storage use karta hai hota hai
or agar ham jo array bana rahe hai wo agar stack wale memory me jitna storage hai
usse jyada storage ka ho toh usse heap me store karana padega
Heap wale me store karane ke liye hame (new) keyword ka istamal karna padta hai
*/