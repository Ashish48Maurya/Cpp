
// #include<iostream>
// using namespace std;
// class student{
//     public:
//     int age;
//     string name;
//     bool gender;
// };
// int main(){
//     //First Method to declare a object of a Class.
//     student s1;
//     s1.name = "Ashish";
//     s1.age = 19;
//     s1.gender = 1;
//     cout<<s1.name<<"-"<<s1.age<<"-"<<s1.gender<<endl;

//     //Second Method to declare a object of a Class.
//     student *s2 = new student();
//     s2->name = "Maurya";
//     s2->age =  20;
//     s2->gender = 1;
//     cout<<s2->name<<"-"<<s2->age<<"-"<<s2->gender;
// return 0;
// }

// #include<iostream>
// using namespace std;
// class student{
//     string name;
//     public:
//     int age;
//     bool gender;
//     void  setname(string name){
//         this->name = name;
//        here this is pointing to the object who called this function
//     }
//     void  getname(){
//         cout<<name<<endl;
//     }
// };
// int main(){
//     student s;
//     s.setname("Ashish");
//     s.getname();
//     s.age = 19;
//     cout<<s.age;
// return 0;
// }


// #include<iostream>
// using namespace std;
// class student{
//      string name;
//     public:
//     int age;
//     bool gender;

//     student (string s, int a, int g){
//         name = s;
//         age= a;
//         gender = g;
//     }

//     // void setname(string s){
//     //     name =s ;
//     // }
//     void getname(){
//         cout<<name<<endl;
//     }
// };
// int main(){
//  student a("Ashish",19,1);
//  a.getname();
//  cout<<a.age<<"-"<<a.gender;
// return 0;
// }
