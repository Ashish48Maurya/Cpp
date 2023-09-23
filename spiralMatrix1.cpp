//Given a Square Matrix of order n*n fill the element in matrix in spiral order starting from 1 upto n^2;
//    {{1 2 3}
//     {8 9 4}   if n=3;
//     {7 6 5}}
#include<iostream>
#include<vector>
using namespace std;

void spiralMatrix(vector<vector<int>> &V){
    int top = 0;
    int bottom = V.size()-1;
    int left = 0;
    int right = V.size()-1;
    int value = 1;
    int n = V.size();

    int direction = 0;
    while(bottom>=top && right>=left){

        // left --> right
        if(direction==0){
            for(int col=left; col<=right; col++){
                V[top][col] = value;
                value++;
            }
            top++;
        }

        //top --> bottom
        else if(direction==1){
            for(int row=top; row<=bottom; row++){
                V[row][right] = value;
                value++;
            }
            right--;
        }

        //right --> left
        else if(direction==2){
            for(int col=right; col>=left; col--){
                V[bottom][col] = value;
                value++;
            }
            bottom--;
        }

        //bottom --> top
        else{
            for(int row=bottom; row>=top; row--){
                V[row][left] = value;
                value++;
            }
            left++;
        }

        direction = (direction+1)%4;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<V[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    int n;
    printf("Enter Value of n: ");
    scanf("%d",&n);
    vector<vector<int>> vec(n,vector<int>(n));
    spiralMatrix(vec);
    return 0;
}