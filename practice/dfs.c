#include <stdio.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int matrix[7][7] = {{0, 1, 1, 3, 0, 0, 0},
                    {1, 0, 1, 1, 0, 0, 0},
                    {1, 1, 0, 1, 1, 0, 0},
                    {1, 1, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i){
    printf("%d ",i);
    visited[i] = 1;
    for(int j=0; j<7; j++){
        if(matrix[j][i]==1 && visited[j]!=1){
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}