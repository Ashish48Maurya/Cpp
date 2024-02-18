#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> q = {4,2,0,5,2,6,2,3};

    // vector<int> leftMax;
    // leftMax.push_back(0);
    // for(int i=0; i<q.size(); i++){
    //     int num = max(leftMax[i],q[i]);
    //     leftMax.push_back(num);
    // }
    

    // vector<int> rightMax(q.size(), 0);
    // for(int i=q.size()-1; i>0; i--){
    //     int num = max(rightMax[i] , q[i]);
    //     rightMax[i-1] = num;
    // }
    // int water = 0;
    // for(int i=0; i<q.size(); i++){
    //     int num = min(rightMax[i],leftMax[i]);
    //     if(num - q[i] > 0){
    //         water += num-q[i];
    //     }
    //     else{
    //         water += 0;
    //     }
    // }
    // cout<<water<<endl;



    //More Optimised Approach
    int maxEle = q[0];
    int index = 0;

    for(int i=1; i<q.size(); i++){
        if(q[i] > maxEle){
            maxEle = q[i];
            index = i;
        }
    }
    
    int leftMax = 0;
    int water = 0;

    //LeftMax is Known to Us
    for(int i=0; i<index; i++){
        if(leftMax > q[i]){
            water += (leftMax - q[i]);
        }
        else{
            leftMax = q[i];
        }
    }

    int rightMax = 0;
    //RightMax is Known to Us
    for(int i = q.size()-1; i>index; i--){
        if(rightMax > q[i]){
            water += (rightMax - q[i]);
        }
        else{
            rightMax = q[i];
        }
    }

    printf("Water Stored in Area : %d",water);
    return 0;
}