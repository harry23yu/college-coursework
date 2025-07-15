/* bag2set.c */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"
/* Converts the input bag into a set using dynamic arrays 
param:  da -- pointer to a bag 
return value: void
        result: after exiting the function da points to a set 
*/

/*Run the first part of HW2 with gcc bag2set.c dynArray.c dynArray.h, then a.out*/

void bag2set(struct DynArr *da) {   
     /* FIX ME */
     assert(da!=NULL);
     int i, j, k;
     for (i = 0; i < da->size; i++) {
        for (j = i + 1; j < da->size; j++) {
                if (EQ(da->data[i], da->data[j])) {
                        for (k = j; k < da->size - 1; k++) {  
                                da->data[k] = da->data[k + 1];  
                        }
                        da->size--;
                        j--; 
                }
        }
     }
}

/* An example how to test your bag2set() */
int main (int argc, char* argv[]) {
int i;
        struct DynArr da;  /* bag */
        
        initDynArr(&da, 100);
        da.size = 11;
        da.data[0] = 1.3;
for (i=1; i<da.size-1; i++) {
    da.data[i] = 1.2;
}
        da.data[da.size-1] = 1.4;
        printf("Bag:\n\n");
for (i=0;i<da.size;i++) {
        printf("%g  \n", da.data[i]);
}
        
        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(&da);
for (i=0; i<da.size; i++) {
          printf("%g ", da.data[i]);
}
        printf("\n");
if (&da) {
        freeDynArr(&da);
}
return 0;
}