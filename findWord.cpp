#include<stdio.h>
#include<string.h>
int main(){
    char str1[1000];
    char str2[1000];
    gets(str1);
    int length = strlen(str1);
    for(int i=0; i<length; i++){
        str2[length-1-i] = str1[i];
    }
    puts(str2);
    return 0;
}