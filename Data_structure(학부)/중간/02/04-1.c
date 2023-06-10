#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("strings.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 0;
    }
    char **arr = (char**)malloc(sizeof(char*)*5);

    for(int i = 0; i < 5; i++) {
        char buffer[20];
        fscanf(fp, "%s", buffer);
        arr[i] = (char*)malloc(sizeof(char)*strlen(buffer)+1);
        if(arr[i] == NULL) {
            printf("malloc error\n");
            return 0;
        }
        strcpy(arr[i], buffer);
    }

    for(int i = 0; i < 4; i++) {
        int minIdx = i;
        for(int j = i+1; j < 5; j++) {
            if(strcmp(arr[minIdx], arr[j]) > 0) {
                char buffer[20];
                strcpy(buffer, arr[minIdx]);
                strcpy(arr[minIdx], arr[j]);
                strcpy(arr[j], buffer);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr); fclose(fp);
    return 0;
}