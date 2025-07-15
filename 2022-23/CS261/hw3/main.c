#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"
/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers separated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file); /* prototype */
/****************************************/
int main (int argc, const char * argv[]) {
    /*Write this function*/
    const char* nameOfFile = argv[1];
    int i;
    int* count;
    char* temp;
    struct hashMap ht; /*Initialize hashtable*/
    FILE *file;
    struct hashLink* link;
    /*int bucket;*/

    initMap(&ht, 10);

    printf("Please enter file name:\n");
    if (argc==2) {
        if ((file = fopen(nameOfFile, "r"))) {
            printf("File exists\n");
        }
        else {
            printf("File doesn't exist\n");
        }
    }
    
    /*The word is the key. The number of times the word appears will be the value.*/

    while (!feof(file)) {
        temp = getWord(file);
        count = atMap(&ht, temp);
        if (count) { /*this never evaluates to be true*/
            (*count)++;
        }
        else {
            insertMap(&ht, temp, 1);
        }
    }
    fclose(file);
    printf("Number of times each word appears in the file: \n");
    for (i = 0; i < ht.tableSize; i++) {
        link = ht.table[i];
        while (link != NULL) {
            printf("%s : ", link->key);
            printf("%d\n", link->value);
            link = link->next;
        }
    }
    freeMap(&ht);
    return 0;
}   

char* getWord(FILE *file)
{
int length = 0;
int maxLength = 16;
char character;
    
char* word = (char*)malloc(sizeof(char) * maxLength);
assert(word != NULL);
    
while( (character = fgetc(file)) != EOF)
{
if((length+1) > maxLength)
{
maxLength *= 2;
word = (char*)realloc(word, maxLength);
}
if((character >= '0' && character <= '9') || /*is a number*/
   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
   character == 39) /*or is an apostrophy*/
{
word[length] = character;
length++;
}
else if(length > 0)
break;
}
    
if(length == 0)
{
free(word);
return NULL;
}
word[length] = '\0';
return word;
}