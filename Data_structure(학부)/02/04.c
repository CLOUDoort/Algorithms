#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("strings.txt", "r");
    if(fp == NULL){
        printf("Error\n");
        return 1;
    }
    char** stringArr = (char**)malloc(sizeof(char*)*5);
    for(int i = 0; i < 5; i++) {
        char buffer[100];
        fscanf(fp, "%s", buffer);
        stringArr[i] = (char*)malloc(sizeof(char)*strlen(buffer)+1);
        if(stringArr[i] == NULL) {
            printf("Error\n");
            return 1;
        }
        strcpy(stringArr[i], buffer);
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(stringArr[i][0] < stringArr[j][0]) {
                char temp[20];
                strcpy(temp, stringArr[i]);
                strcpy(stringArr[i], stringArr[j]);
                strcpy(stringArr[j], temp);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("%s\n", stringArr[i]);
        free(stringArr[i]);
    } 
    free(stringArr);
    fclose(fp);
}