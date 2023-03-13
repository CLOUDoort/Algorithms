#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("strings.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 1;
    }
    char stringArray[5][20];
    for(int i = 0; i < 5; i++) {
        fscanf(fp, "%s", stringArray[i]);
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(stringArray[i][0] < stringArray[j][0]) {
                char temp[20];
                strcpy(temp, stringArray[i]);
                strcpy(stringArray[i], stringArray[j]);
                strcpy(stringArray[j], temp);
            }
        } 
    }
    for(int i = 0; i < 5; i++) printf("%s\n", stringArray[i]);
    fclose(fp);
}