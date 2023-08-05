#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    int i,c = 0;
    char *p = str;
    printf("%p",p);
    printf("\n%p",&str);
    printf("\nEnter String: ");
    gets(str);
    puts(str);
    //int length = strlen(str);
    while(*p != '\0'){
        c++;
        p++;
    }
    printf("%d",c);
    return 0;
}