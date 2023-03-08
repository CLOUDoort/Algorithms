#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};
    char str3[20] = {"hi"};

    if(!strcmp(str1, str3)) {
        printf("equal \n");
    } else printf("not equal \n");

    return 0;
}