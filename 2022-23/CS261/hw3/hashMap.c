#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <stdio.h> /*new header*/
int stringHash1(char * str)
{
int i;
int r = 0;
for (i = 0; str[i] != '\0'; i++)
r += str[i];
return r;
}
int stringHash2(char * str)
{
int i;
int r = 0;
for (i = 0; str[i] != '\0'; i++)
r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
return r;
}
void initMap (struct hashMap * ht, int tableSize)
{
int index;
if(ht == NULL)
return;
ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
ht->tableSize = tableSize;
ht->count = 0;
for(index = 0; index < tableSize; index++)
ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht) {
    /*write this*/
    int i = 0;
    struct hashLink* temp1;
    struct hashLink* temp2;
    for (i = 0; i < ht->tableSize; i++) {
        temp1 = ht->table[i];
        temp2 = ht->table[i];
        while (temp1 != NULL) {
            temp2 = temp1->next;
            free(temp1);
            temp1 = temp2;
        }
    }
    free(ht->table);
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v) {
    /*write this*/
    hashLink* link;
    hashLink* temp;
    int bucket = stringHash1(k) % ht->tableSize;
    if (!containsKey(ht, k)) { /*this always evaluates to be true, even if the key exists*/
        link = (struct hashLink*) malloc(sizeof(struct hashLink));
        link->key = k;
        link->value = v;
        link->next = ht->table[bucket];
        ht->table[bucket] = link;
        ht->count++;
    }
    else {
        /*new code*/
        temp = ht->table[bucket];
        while (temp != NULL) {
            if (strcmp(temp->key, k) == 0) {
                temp->value = v;
                return;
            }
            else {
                temp = temp->next;
            }
        }
        link = (struct hashLink*) malloc(sizeof(struct hashLink));
        link->key = k;
        link->value = v;
        link->next = ht->table[bucket];
        ht->table[bucket] = link;
        ht->count++;
        /*ink->value = *atMap(ht, k) + 1;*/
    }
}

ValueType* atMap (struct hashMap * ht, KeyType k) {
    /*write this?*/
    int bucket = stringHash1(k) % ht->tableSize;
    struct hashLink *temp;
    temp = ht->table[bucket];
    if (ht->table[bucket] == NULL) {
        return NULL;
    }
    else {
        while (temp != NULL) {
            if (temp->key == k) {
                return &(temp->value);
            }
            else {
                temp = temp->next;
            }
        }
    return NULL;
    }
}

int containsKey (struct hashMap * ht, KeyType k) {
    /*write this*/
    int bucket = stringHash1(k) % ht->tableSize;
    struct hashLink *temp;
    temp = ht->table[bucket];
    if (ht->table == NULL) {
        return 0;
    }
    while (temp != NULL) {
        if (temp->key == k) {
            return 1;
        }
        else {
            temp = temp->next;
        }
    }
    return 0;
}

void removeKey (struct hashMap * ht, KeyType k) {
    /*write this*/
    int bucket = stringHash1(k) % ht->tableSize;
    struct hashLink *temp, *last;
    temp = ht->table[bucket];
    last = ht->table[bucket];
    while (temp != NULL) {
        if (temp->key == k) {
            if (temp == ht->table[bucket]) {
                ht->table[bucket] = temp->next;
            }
            last->next = temp->next;
            free(temp);
            temp = NULL;
            ht->count--;
        }
        else {
            last = temp;
            temp = temp->next;
        }
    }

}

int sizeMap (struct hashMap *ht) {
    /*write this*/
    return ht->count;
}

int capacityMap(struct hashMap *ht) {
    /*write this*/
    return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht) {
    /*write this*/
    int count = 0;
    int i;
    for (i = 0; i < ht->tableSize; i++) {
        if (ht->table[i] == NULL) {
            count++;
        }
    }
    return count;
}

float tableLoad(struct hashMap *ht) {
    /*write this*/
    float tableLoadValue = ht->count / ht->tableSize;
    return tableLoadValue;
}