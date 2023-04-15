#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("strings.txt", "r");
    if(fp == NULL) {
        printf("FILE Error\n");
        return 0;
    }
    char stringArr[5][10];

    for(int i = 0; i < 5; i++) {
        fscanf(fp, "%s", stringArr[i]);
    }

    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            if(strcmp(stringArr[i], stringArr[j]) > 0) {
                char temp[20];
                strcpy(temp, stringArr[i]);
                strcpy(stringArr[i], stringArr[j]);
                strcpy(stringArr[j], temp);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("%s\n", stringArr[i]);
    }

    fclose(fp);
    return 0;
}