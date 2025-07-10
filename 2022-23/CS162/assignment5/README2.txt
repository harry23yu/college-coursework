Hi Caden Burke!

1. Harry Yu, ONID: yuhar

2. In C++, a linked list is like an array of values. However, instead of something like [1, 2, 3], where 
each value is its own self, in a linked list, each value "points" to the next value. A linked list with 3 
integers would look something like this: 1->2->3->NULL. NULL means that the list has terminated. Linked lists 
are divided into "nodes" that contain two parts: a value and a link to the next node. In the above example, 1 
is the value and "->" is the link to the next node. The linked list program for this assignment contains 
functions that help the linked list do a few things, like inserting nodes at different locations, sort the 
nodes in ascending or descending order, and finding the number of prime numbers in the list.

3. For part 2, there is a Makefile. First, type "make" in the terminal. Then, type "driver_run." The user should be 
able to see that in test 1, the length (number of nodes) of the linked list is 0, because there are no values yet. 
However, in test 2.1, five values got added to the front of the linked list. The length is now 5. Press enter to continue 
after finshing a test. In test 2.2, five values got added to the back of the linked list. The length is now 10. In test 2.3, 
three more values got added to the list: one in the front, one in the back, and one between 100 and the first 5. The length 
is now 13. One value isn't printed because it is not a valid index (it's out of bounds).

Test 3.1 is where it gets interesting. All the values are sorted in ascending order using recursive merge sort. Recursive 
merge sort is where the list is divided into the smallest unit (usually 1 element). Compare the values of each element with 
the adjacent list to sort them in ascending order. Then, merge the two adjacent lists. Repeat until all of the elements are sorted 
and merged back together. For example, if a linked list has four elements, 3->2->1->4, this is what merge sort would look like: 

3->2->1->4
3->2 1->4
3 2 1 4 (split the list until each element has only 1 node)
2->3 1->4
1->2->3->4 (sort and merge the list back together)

Test 3.2 is the same as step 3.1 except all of the elements are sorted in descending order using recursive merge sort. Then, in test 4, 
the number that is returned shows the user how many prime numbers are in the list. Negative numbers, 0, and 1 are not prime. So if the list 
includes -12, 0, 1, 2, 3, 10, and 11, 3 will be returned because there are 3 prime numbers (2, 3, and 11). Last but not least, in test 5, 
the entire linked list is deleted, meaning that the length will be reset to 0.

4. A very large prime number (such as 4294963943) cannot be detected because it is just too big. C++ code can only handle numbers up to a certain 
point.

5. I didn't do extra credit

6. For sort_ascending(), I had to first find the middle element. Then, I will continue to split the linked list until every element is its own node. 
Next, I would merge the nodes back together, comparing if the "left" value is greater than the "right" value. If the statement is true, I would swap the 
pointers on the nodes. I would continue to do that until every node that needs to be swapped is swapped. For sort_descending(), I did the same for sort_ascending() 
except I changed the sign comparing the values of the nodes. For count_prime(), I had to loop through every element of the list to check to see if its prime. In 
order to check to see if the number is prime, if the number is divisible by any number from 2 to number-1, then it is not prime. There are special expections: 
negative numbers, 0, and 1 are not prime numbers. 2 is the only even prime number. I had to take these exceptions into account. The number of primes started 
at 0; when a number is prime, then number of primes increased by 1. I returned number of primes in the end.

For recursive merge sort, the runtime complexity using Big O is O(n*log(n)). This is true for both sort_ascending() and sort_descending().

For count_prime(), the runtime complexity using Big O is O(N), where N is the length of the linked list.