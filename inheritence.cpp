#include<iostream>
using namespace std;

//Single level inheritance
// class Animal{
//     public:
//     string color;
//     void eat(){
//         cout<<"Eats"<<endl;;
//     }
//     void breathe(){
//         cout<<"Breathes"<<endl;
//     }
// };

// class Fish: public Animal{
//     public:
//     int fins;
// };

//Multiple inheritance
class parent1{
    public:
    parent1(){

    cout<<"I am Parent 1"<<endl;
    }
};

class parent2{
    public:
    parent2(){

    cout<<"I am Parent 2"<<endl;
    }
};

class child: public parent1,parent2{
    public:
    child(){
        cout<<"Constructor Called..."<<endl;
    }
};

// Multi Level Inheritance
class Animal{
    public:
    void breathe(){
        cout<<"Breathes"<<endl;
    }
    void eats(){
        cout<<"Eats"<<endl;
    }
};

class Mammal: public Animal{
    public: 
    int legs;
    void sleep(){
        cout<<"Sleeps"<<endl;
    }
};

class Human: public Mammal{
    public: 
    string name;
    string color;
};

int main(){
    // Fish *f1 = new Fish();
    // f1->color = "Silver";
    // f1->fins = 2;
    // f1->eat();
    // f1->breathe();
    // cout<<f1->color<<endl;
    // cout<<f1->fins<<endl;

    //child c1;

    Human h1;
    h1.breathe();
    h1.color = "B/W";
    h1.sleep();
    h1.name = "Insaan";
    cout<<h1.name<<" - "<<h1.color;
    return 0;
}