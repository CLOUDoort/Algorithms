/*
- 파일로부터 문자열 입력받아 정수로 바꾸고, 그 정수를 hashFunc에 넣어 Key값을 받는다.
- 받은 key값을 인덱스로 하는 table에 문자열을 저장한다.
- search 파일로부터 문자열 입력받아 정수로 바꾸고, 이전에 입력한 데이터의 정수값과 비교해서 탐색 성공과 실패를 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 10

typedef struct element {
    char data[4];
    int key;
} element;
element table[MAX_ELEMENT];

unsigned int stringToInt(char *key);
int hashFunc(int key, int d);
element* search(int k, int d);

int main() {
    FILE* fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    FILE* fp2 = fopen("search.txt", "r");
    if(fp2 == NULL) {
        if(fp2 == NULL) {
            printf("file read error\n");
            exit(1);
        }
    }
    int d; // hash table 크기
    scanf("%d", &d);
    char temp[4];
    // insertion
    while(fscanf(fp1, "%s", temp) != EOF) {
        int int_number = stringToInt(temp);
        int key = hashFunc(int_number, d);
        if(!search(int_number, d)) {
            table[key].key = int_number;
            strcpy(table[key].data, temp);
        }
        else {
            printf("table full\n");
            exit(1);
        }
    }

    printf("\n");
    while(fscanf(fp2, "%s", temp) != EOF) {
        int search_number = stringToInt(temp);
        int flag = 0;
        for(int i = 0; i < d; i++) {
            if(search(search_number, d)) {
                printf("S\n");
                flag = 1;
                break;
            }
        }
        if(!flag) printf("E\n");
    }

    printf("\n");
    for(int i = 0; i < d; i++) {
        if(table[i].key) {
            printf("%d: %s (%d)\n",i, table[i].data, table[i].key);
        }
        else printf("%d: \n", i);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

element* search(int k, int d) {
    int homeBucket, currentBucket;
    homeBucket = hashFunc(k, d);
    for(currentBucket = homeBucket; table[currentBucket].key && table[currentBucket].key != k;) {
        currentBucket = (currentBucket+1)%d;
        if(currentBucket == homeBucket) return NULL;
    }
    if(table[currentBucket].key == k) {
        return &table[currentBucket];
    }
    return NULL;
}


int hashFunc(int key, int d) {
    return key%d;
}

unsigned int stringToInt(char *key) {
    int number = 0;
    while(*key) {
        number += *key++;
    }
    return number;
}