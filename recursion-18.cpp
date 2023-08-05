//find total no. of ways in which n friends can remain single or can be paired up

#include<iostream>
using namespace std;
//Base Case
int friendpair(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }

// Self work is to add total no. of ways given by recursion and also complete your responsibility for 1st friend

//Recursive work

//(1st if you want pairing of friend) :- I will pair 1st friend your work is to return total no. of ways (n-2) friends can be paired up;

//(n-1) --> because 1st wale friend ko pair karne ke (n-1) ways hai with (n-1) students
    int doublepair = (n-1)*friendpair(n-2);


//(2nd if you want to keep all friend single):- I will complete task for 1st friend your task is to return total no. of ways (n-1) friends can remain single
int singlepair = 1*friendpair(n-1);

    return singlepair+doublepair;
}
int main(){
cout<<friendpair(4);
return 0;
}