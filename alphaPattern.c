//13
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int vacSpace = n-i;
        for(int j=0; j<vacSpace; j++){
            printf(" ");
        }
        int no_of_char = 2*i-1;
        for(int j=0; j<no_of_char; j++){
            printf("%c",'A'+j);
        }
        printf("\n");
        }
        for(int i=n+1; i<2*n; i++){
            int lVacSpace = i-n;
            int l_no_of_char = 2*(2*n-i)-1;
            for(int i=0; i<lVacSpace; i++){
                printf(" ");
            }
            for(int j=0; j<l_no_of_char; j++){
                printf("%c",'A'+j);
            }
            printf("\n");
        }
        printf("\n");
    return 0;
}