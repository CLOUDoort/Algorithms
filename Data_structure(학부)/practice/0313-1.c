#include <stdio.h>

int main(void) {
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    if(input_file == NULL) {
        printf("Error\n");
        return 1;
    }
    // output_file = fopen("output.txt", "w");
    // if(output_file == NULL) {
    //     printf("Error\n");
    //     return 1;
    // }
    char word[100];
    while(fscanf(input_file, "%s", word) == 1) {
        printf("RealWord : %s\n", word);
    }

    fclose(input_file);
}