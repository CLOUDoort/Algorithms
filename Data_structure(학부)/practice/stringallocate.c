#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char* str = NULL;
    int len;
    printf("Enter the length of the string: ");
    scanf("%d", &len);
    str = (char*)malloc(sizeof(char)*len+1);
    printf("Enter the string: ");
    scanf("%s", str);
    printf("The entered string is : %s\n",str);
    free(str);
    return 0;
}