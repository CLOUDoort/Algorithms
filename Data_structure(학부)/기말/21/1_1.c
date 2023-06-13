#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 10

typedef struct element* htPointer;
typedef struct element {
    char data[4];
    int key;
} element;
htPointer ht[MAX_ELEMENT];

unsigned int stringToInt(char *key);
int hashFunc(int key, int d);
int findKey(int k, int d);
element* search(int k, int d);
htPointer createNode();

int main() {
    FILE*fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    FILE*fp2 = fopen("search.txt", "r");
    if(fp2 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int d; scanf("%d", &d);
    // 구조체 포인터 배열 초기화
    for(int i = 0; i < d; i++) {
        ht[i] = createNode();
    }

    // insertion
    char temp[4];
    while(fscanf(fp1, "%s", temp) != EOF) {
        int sToi = stringToInt(temp);
        int key = findKey(sToi, d);
        if(key != -1) {
            strcpy(ht[key]->data, temp);
            ht[key]->key = sToi;
        }
        else {
            printf("hash table full\n");
        }
    }
    while(fscanf(fp2, "%s", temp) != EOF) {
        int sToi = stringToInt(temp);
        if(search(sToi, d)) {
            printf("S\n");
            continue;
        }
        printf("E\n");
    }
    printf("\n");
    for(int i = 0; i < d; i++) {
        if(ht[i]->key) {
            printf("%d: %s (%d) \n", i, ht[i]->data, ht[i]->key);
        }
        else printf("%d: \n", i);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

int findKey(int k, int d) {
    int homeBucket, currentBucket;
    homeBucket = hashFunc(k, d);
    currentBucket = homeBucket;
    while(ht[currentBucket]->key) {
        currentBucket = (currentBucket+1)%d;
        if(currentBucket == homeBucket) return -1;
    }
    return currentBucket;
}

element* search(int k, int d) {
    int homeBucket, currentBucket;
    homeBucket = hashFunc(k, d);
    for(currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;) {
        currentBucket = (currentBucket+1)%d;
        if(currentBucket == homeBucket) return NULL;
    }
    if(ht[currentBucket]->key == k) {
        return ht[currentBucket];
    }
    return NULL;
}

int hashFunc(int key, int d) {
    return key % d;
}

unsigned int stringToInt(char *key) {
    int number = 0;
    while(*key) {
        number += *key++;
    }
    return number;
}

htPointer createNode() {
    htPointer newNode = (htPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}