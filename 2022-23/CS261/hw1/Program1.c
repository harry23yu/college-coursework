/* CS261- HW1 - Program1.c*/
/* Name: Harry Yu
 * Date: 1/20/2023
 * Solution description: x, y, and z will be three random integers from 0 to 10. x will be incremented, 
 y will be decremented, and z will stay the same after the foo function is executed. The return value 
 is x - y.
 */

/*Only sumbit C files, not makefile*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) { 
    /* Increment a */
    (*a)++;
    /* Decrement  b */
    (*b)--;
    /* Assign a-b to c */
    c = (*a) - (*b);
    /* Return c */
    return c;
}

int main() {
    /* Declare three integers x,y and z and initialize them randomly to values in 
[0,10] */
    int x, y, z;
    srand(time(NULL));
    x = rand() % 11;
    y = rand() % 11;
    z = rand() % 11;
    /* Print the values of x, y and z */
    printf("Values of x, y, and z, respecitvely: %d %d %d\n", x, y, z);
    /* Call foo() appropriately, passing x,y,z as parameters */
    int newInt = foo(&x, &y, z);
    /* Print the values of x, y and z */
    printf("New values of x, y, and z, respecitvely: %d %d %d\n", x, y, z);
    /* Print the value returned by foo */
    printf("The value returned by foo is %d\n", newInt);
    /* Is the return value different than the value of z?  Why? */
    /*The return value is different than the value of z because z was passed into the foo function by value, instead of a pointer. 
    There is no ampersand in front of the z.*/
    return 0;
} 