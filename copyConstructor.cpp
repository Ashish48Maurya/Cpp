#include<iostream>
using namespace std;
// class ke andar ke sab by default private hote hai
class student1{
    string name;
public:
int age;
bool gender;

student1 (int a, string s, int g){
    age = a;
    name = s;
    gender= g;
}

student1(student1 &a){
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

void setname(string s){
    name = s;
}
void  getname(){
    cout<<name;
}
void printinfo(){
    cout<<"Name = ";
    cout<<name<<endl;
    cout<<"Age = ";
    cout<<age<<endl;
    cout<<"Gender = ";
    cout<<gender<<endl;
    
}
};
int main(){
    student1 a(19, "Ashish", 1);
    a.printinfo();
    student1 b=a;
    b.printinfo();
    return 0;
}