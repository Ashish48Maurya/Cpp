#include<iostream>
using namespace std;
class Student{
protected:
    int roll_no;
public:
    void set_roll_no(int n){
        roll_no = n;
    }
    void get_roll_no(){
        cout<<"Your roll no is" << roll_no <<endl;
    }
};
class Test : virtual public Student{
protected: 
    int physics , maths;
public:
    void set_marks(int m1 , int m2){
        physics = m1;
        maths = m2;
    }
    void get_marks(){
        cout<<"Your marks : "<<"In physics: "<< physics <<endl<<"In maths: "<<maths<<endl;
    }
};
class Sports : virtual public Student{
protected:
    int score;
public:
    void set_score(int sc){
        score = sc;
    }
    void get_score(){
        cout<<"Your score is: "<<score<<endl;
    }
};
class Result : public Test , public Sports{
public:
         void Display(){
        cout<<"Your overall result is: "<<(physics + maths + score)<<endl;
    }
};
int main(){
    Result r;
    r.set_roll_no(420);
    r.set_marks(98 , 97);
    r.set_score(10);
    r.Display();
    return 0;
}