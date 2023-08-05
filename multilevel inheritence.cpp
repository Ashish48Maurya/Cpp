#include<iostream>
using namespace std;
class student{
protected: int roll_number;
public: void setroll_number(int);
        void getroll_number();
};
void student :: setroll_number(int r){
        roll_number = r;
}
void student :: getroll_number(){
        cout<<roll_number<<endl;
}
class Exam : public student{
protected:
     int  maths;
     int  physics;
public:
        void setmarks(int , int);
        void getmarks();
};
void Exam :: setmarks(int m1 , int m2){
        maths = m1;
        physics = m2;
}
void Exam :: getmarks(){
        cout<<"The marks obtained in maths are: "<< maths<<endl;
        cout<<"The marks obtained in physics are: "<< physics<<endl;
}
class Result : public Exam{
        float Percentage;
public:
        void display(){
                getroll_number();
                getmarks();
        cout<< "Your Percentage is: "<< (maths+physics)/2 <<"%"<<endl;
        }
};
int main(){
        Result Ashish;
        Ashish.setroll_number(26);
        Ashish.setmarks(99 , 97);
        Ashish.display();
return 0;
}