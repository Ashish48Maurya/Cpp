#include<stdio.h>
#include<string.h>
int main(){
    char str1[1000];
    char str2[1000];
    char *p = str1;
    char *q = str2;
    int f=0;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    while(*p != '\0' && *q != '\0'){
        if(*p != *q){
            f=0;
            break;
        }
        else{
            f=1;
        }
        p++;
        q++;
    }
    if(f==0){
        printf("String are Not Equal");
    }
    else{
        printf("String are Equal");
    }
    return 0;
}