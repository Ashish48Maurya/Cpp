//You have given a matrix along with integers r1,c1,r2,c2 find the sum of elements of a matrix which is enclosed within the rectangle/square formed by the given integers
//(e.g) =>   1 2 3
//           4 5 6       if r1,r2,c1,c2 is 0,1,1,2 then sum ?
//           7 8 9        sum = 2+3+5+6 => 16
#include<iostream>
using namespace std;
int main(){
    int r1,r2,c1,c2;
    cin>>r1>>r2>>c1>>c2;

    int arr[3][4] = {{1,2,3,4},
                     {5,6,7,8},
                     {9,10,11,12}};


    int sum = 0;
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            sum += arr[i][j];
        }
    }

    cout<<"Sum: "<<sum<<endl;
    return 0;
}