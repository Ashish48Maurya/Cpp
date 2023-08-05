//Time complexity hamesha bade input ke liye dekhte hai

// #include<stdio.h>
// int main(){
//     int ans = 0;
//     int m; scanf("%d",&m);
//     int n;  scanf("%d",&n);
//     for(int i=m; i<=n; i++){
//         ans += i;
//     }
//     //idhar loop n-m+1 baar chal raha hai aur agar --> n = big input value rahega(1e5) and m = chota value toh total (1e5)=n baar loop chalega 
//     //Ye accha time complexity nahi hai
//     printf("%d",ans);
//     return 0;
// }

#include<stdio.h>
int optemised_sum(int x,int y){
    int n = y-x+1;
    int a = x;
    int ans = (n*(2*a + (n-1)*1))/2;
    //Idhar kitna bhi bada input rahane do time complexity hamesha constant hi rahega (i.e) --> O(6)
    //Qki sirf 6 operation hoga hamesha  3times -> * , 1->+ , 1-> - , 1-> /  
    return ans;
}
int main(){
    printf("%d",optemised_sum(2,6));
    return 0;
}