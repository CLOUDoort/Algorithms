#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 10

typedef struct node* nodePointer;
typedef struct node {
    char data[4];
    int key;
    nodePointer link;
} node;
nodePointer ht[MAX_ELEMENT];

nodePointer createNode();
unsigned int stringToInt(char *key);
int hashFunc(int k, int d);
nodePointer findKey(int k, int d);
nodePointer search(int k, int d);

int main() {
    FILE* fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    FILE* fp2 = fopen("search.txt", "r");
    if(fp2 == NULL) {
        printf("file read error\n");
        exit(1);
    }

    int d; scanf("%d", &d);
    for(int i = 0; i < d; i++) {
        ht[i] = createNode();
    }
    
    // insertion
    char temp[4];
    while(fscanf(fp1, "%s", temp) != EOF) {
        int sToi = stringToInt(temp);
        nodePointer newNode = createNode(), preLink = findKey(sToi, d);
        if(preLink) {
            newNode->key = sToi; newNode->link = NULL;
            strcpy(newNode->data, temp);
            preLink->link = newNode;
        }
        else {
            printf("find key error\n");
            exit(1);
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
        nodePointer current = ht[i]->link;
        if(current) {
            while(current) {
                printf("%d: %s (%d)\n", i, current->data, current->key);
                current = current->link;
            }
        } else {
            printf("%d: \n", i);
        }
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

nodePointer findKey(int k, int d) {
    int homeBucket = hashFunc(k, d);
    nodePointer current = ht[homeBucket];
    while(current->link) {
        current = current->link;
    }
    return current;
}

nodePointer search(int k, int d) {
    nodePointer current;
    int homeBucket = hashFunc(k, d);
    for(current = ht[homeBucket]; current; current = current->link) {
        if(current->key == k) return current;
    }
    return NULL;
}

int hashFunc(int k, int d) {
    return k % d;
}

unsigned int stringToInt(char *key) {
    int number = 0;
    while(*key) {
        number += *key++;
    }
    return number;
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}