/* binary search ka time complexity kam hota hai as compared to linear search
because binary search me ham kisi bhi beech wale  number se suru karte hai search karna and linear search
 me starting se end point tak search karna padta hai  */


 /*    Binary search me sorted array rahena chaiye      */
 /* sorted array means array ke elements increasing order me arrange rahenge      */

 #include<iostream>
 using namespace std;
 int binarysearch (int array[], int n, int key){
    int s=0;    // s= starting point
    int e=n;    // e= end point
    while(s<=e){
        int mid=(s+e)/2;
        if (array[mid]==key){
            return mid;
        }
        else if(array[mid]>key){
            e=mid-1;
        }
        else{s=mid+1;}
    }
    return -1;

 }

 int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int key;
    cin>>key;

    cout<<binarysearch(array,n,key);
   return 0;
 }