#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n = 5;
    char** str_arr = (char**)malloc(sizeof(char*)*n);
    if(str_arr == NULL) {
        printf("Error\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        char buffer[100];
        printf("Enter string #%d : ", i+1);
        scanf("%s", buffer);
        str_arr[i] = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
        if(str_arr[i] == NULL) {
            printf("Error\n");
            return 1;
        }
        strcpy(str_arr[i], buffer);
    }
    printf("Entered strings\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", str_arr[i]);
    }
    for(int i = 0; i < n; i++) {
        free(str_arr[i]);
    }
    free(str_arr);
}