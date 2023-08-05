//copy one array into other using pointer
#include<iostream>
using namespace std;
int main(){
char str1[1000];
char str2[1000];
gets(str1);
char *p = str1, *q=str2;
while(*p!='\0'){
*q = *p;
p++;
q++;
}
printf("string 2 is: ");
puts(str2);
return 0;
}