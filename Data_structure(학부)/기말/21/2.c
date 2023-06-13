/*
- element 포인터 배열을 선언하고 Node 만들어 삽입한다.
- 데이터를 Key값에 맞춰 삽입하는데, Null이 나오면 삽입하고, 데이터가 반환되면 꽉 찼다고 말해준다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 10

typedef struct element* elementPointer;
typedef struct element {
    char data[4];
    int key;
    elementPointer link;
} element;
elementPointer ht[MAX_ELEMENT];

elementPointer createNode();
int hashFunc(int key, int d);
unsigned int stringToInt(char *key);
elementPointer search(int k, int d);

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

    int d;
    scanf("%d", &d);
    char temp[4];
    for(int i = 0; i < d; i++) {
        ht[i] = createNode();
    }
    while(fscanf(fp1, "%s", temp) != EOF) {
        int num = stringToInt(temp);
        int key = hashFunc(num, d);
        if(!search(num, d)) {
            strcpy(ht[key]->data, temp);
            ht[key]->key = num;
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
        if(ht[i]->key) {
            printf("%d: %s (%d)\n",i, ht[i]->data, ht[i]->key);
        }
        else printf("%d: \n", i);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

elementPointer createNode() {
    elementPointer newNode = (elementPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("Malloc error\n");
        exit(1);
    }
    return newNode;
}

elementPointer search(int k, int d) {
    elementPointer current;
    int homeBucket = hashFunc(k, d);
    for(current = ht[homeBucket]; current; current = current->link) {
        if(current->key == k) return current;
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