#include <stdio.h>
#include <string.h>

void revstr(char *ch)
{
    int length = strlen(ch);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = ch[i];
        ch[i] = ch[length - 1 - i];
        ch[length - 1 - i] = temp;
    }
}

int main()
{
    char arr0[] = "Ashish";
    for (int i = 0; i < 6; i++)
    {
        printf("%c", arr0[i]);
    }

    // compiler assume this -> '\0' as a single character
    char arr[] = "Ashish Maurya"; // Compiler will automatically adds \0 at the end of the string if written in this form and that's why we are getting size as 14
    char arr1[] = "ASHISH MAURYA\0";
    int i = 0;
    while (arr[i] != '\0')
    {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");

    int j = 0;
    while (arr1[j] != '\0')
    {
        printf("%c", arr1[j]);
        j++;
    }

    printf("\n");
    char arr2[] = "Dream Company Microsoft";
    puts(arr2);

    printf("\n");
    char arr3[100];
    gets(arr3);
    puts(arr3);

    char ch[] = "Ashish is Good Web Developer";
    int len = strlen(ch);
    printf("%d\n", len);

    revstr(ch);

    printf("%s", ch);
    return 0;
}