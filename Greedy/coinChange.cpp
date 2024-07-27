#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCoins(vector<int> coins,int coin){
    sort(coins.begin(),coins.end());
    int count=0;
    for(int i=coins.size()-1;i>=0; i--){
        while(coins[i] <= coin){
            coin -= coins[i];
            count++;
        }
    }
    return count;
}

int main(){
    int coin = 6;
    vector<int> coins = {1,3,5,2};
    int ans = minCoins(coins,coin);
    cout<<ans;
    return 0;
}