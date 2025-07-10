/******************************************************
** Program: linked_list.cpp
** Author: Harry Yu
** Date: 12/4/2022
** Description: This program contains functions that help the linked list do 
a variety of stuff, such as inserting nodes at different locations, sort the 
nodes in ascending or descending order, and finding the number of prime numbers 
in the linked list.
** Input: None
** Output: The updated linked list.
******************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "linked_list.h"

/*********************************************************************
** Function: Linked_List::Linked_List()
** Description: The default constructor initializes the length of the linked list 
to be 0 and the head to be NULL.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The length should be 0 and the head should be NULL.
*********************************************************************/
Linked_List::Linked_List() {
    this->length = 0;
    this->head = NULL;
}

/*********************************************************************
** Function: int Linked_List::get_length()
** Description: Returns the length (number of nodes) of the linked list.
** Parameters: None
** Pre-Conditions: Length should be 0.
** Post-Conditions: Length should be the number of nodes in the linked list.
*********************************************************************/
int Linked_List::get_length() {
    this->length = 0;
    Node* element = head; //initialize element to be the head (first node) 
    while (element != NULL) {
        length++;
        element = element->next;
    }
    return this->length;
}

/*********************************************************************
** Function: Node* Linked_List::get_head()
** Description: Returns the head (the first node) of the linked list.
** Parameters: None
** Pre-Conditions: The linked list must have at least one node (otherwise there 
will be a seg fault).
** Post-Conditions: The head should be the first node of the linked list.
*********************************************************************/
Node* Linked_List::get_head() { //new function
    return this->head;
}

/*********************************************************************
** Function: void Linked_List::print()
** Description: Outputs a list of all the integers in the linked list.
** Parameters: None
** Pre-Conditions: There should be at least one node in the linked list.
** Post-Conditions: All the values in the list should be printed.
*********************************************************************/
void Linked_List::print() {
    Node* temp = head;
    while (temp != NULL) { //repeat until all nodes have been printed out
        cout << temp->val << " "; //prints the value of the node
        temp = temp->next;
    }
}

/*********************************************************************
** Function: void Linked_List::clear()
** Description: Deletes the linked list.
** Parameters: None
** Pre-Conditions: A linked list exists.
** Post-Conditions: There should be no memory leaks.
*********************************************************************/
void Linked_List::clear() {
    Node* temp = head;
    Node* nextNode = NULL;
    while (temp != NULL) { //repeat until all nodes have been deleted
        nextNode = temp->next;
        delete temp; //deletes the node
        temp = nextNode;
    }
    head = NULL;
}

/*********************************************************************
** Function: void Linked_List::push_front(int i)
** Description: Inserts a new value at the front of the linked list.
** Parameters: int i
** Pre-Conditions: None
** Post-Conditions: A new value should be inserted at the front of the list.
*********************************************************************/
void Linked_List::push_front(int i) {
    Node* temp = new Node();
    temp->val = i;
    temp->next = head; //adds the new value to the front of the list
    head = temp;
}

/*********************************************************************
** Function: void Linked_List::push_back(int i)
** Description: Inserts a new value at the back of the linked list.
** Parameters: int i
** Pre-Conditions: None
** Post-Conditions: A new value should be inserted at the back of the list.
*********************************************************************/
void Linked_List::push_back(int i) {
    Node* newNode = new Node();
    newNode->val = i;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; //adds the new value to the back of the list
    newNode->next = NULL;
}

/*********************************************************************
** Function: void Linked_List::insert(int val, unsigned int index)
** Description: Inserts a new value to the linked list at the specified index.
** Parameters: int val, unsigned int index
** Pre-Conditions: None
** Post-Conditions: The value needs to be inserted at the specified index. If the index 
is not a valid index, then an error message needs to be printed.
*********************************************************************/
void Linked_List::insert(int val, unsigned int index) {
    if (index < 0 || index > length) { //index is out of bounds
        cout << val << " is not inserted because " << index << " is not a valid index." << endl;
    }
    else {
        while (index >= 0) {
            if (index == 0) { //front of the list
                push_front(val);
                return;
            }
            if (index == length) { //back of the list
                push_back(val);
                return;
            }
            if (index > 0 && index < length) { //somewhere in between
                Node* ptr = head;
                ptr = head;
                for (unsigned int i = 0; i < index - 1; i++) {
                    ptr = ptr->next;
                }
                Node* newNode = new Node();
                newNode->val = val;
                newNode->next = ptr->next;
                ptr->next = newNode;
                return;
            }
        }
    }
}

/*********************************************************************
** Function: Node* Linked_List::merge_ascending(Node* left, Node* right)
** Description: Merges and sorts the linked list in ascending order.
** Parameters: Node* left, Node* right
** Pre-Conditions: The list should have been splitted already.
** Post-Conditions: The list should print out all the values in ascending order.
*********************************************************************/
Node* Linked_List::merge_ascending(Node* left, Node* right) { 
    Node* mergedNode = NULL;
    Node* temp = NULL;
    mergedNode = temp;
    while (left != NULL && right != NULL) { //if both left and right is not NULL, the values of the two nodes can be compared 
        if (left->val < right->val) {
            if (mergedNode == NULL) { //if mergedNode is NULL, append the left node
                mergedNode = left;
                temp = mergedNode;
                left = left->next;
            }
            else { //add next node
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
        }
        else {
            if (mergedNode == NULL) { //if mergedNode is NULL, append the right node
                mergedNode = right;
                temp = mergedNode;
                right = right->next;
            }
            else { //add next node
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }
    }
    while (left != NULL) { //remaining nodes in left gets appended to the temp list
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while (right != NULL) { //remaining nodes in right gets appended to the temp list
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    return mergedNode; //returns the merged node
}

/*********************************************************************
** Function: Node* Linked_List::merge_descending(Node* left, Node* right)
** Description: Merges and sorts the linked list in descending order.
** Parameters: Node* left, Node* right
** Pre-Conditions: The list should have been splitted already.
** Post-Conditions: The list should print out all the values in descending order.
*********************************************************************/
Node* Linked_List::merge_descending(Node* left, Node* right) { 
    Node* mergedNode = NULL;
    Node* temp = NULL;
    mergedNode = temp;
    while (left != NULL && right != NULL) { //if both left and right is not NULL, the values of the two nodes can be compared 
        if (left->val > right->val) {
            if (mergedNode == NULL) { //if mergedNode is NULL, append the left node
                mergedNode = left;
                temp = mergedNode;
                left = left->next;
            }
            else {
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
        }
        else {
            if (mergedNode == NULL) { //if mergedNode is NULL, append the right node
                mergedNode = right;
                temp = mergedNode;
                right = right->next;
            }
            else {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }
    }
    while (left != NULL) { //remaining nodes in left gets appended to the temp list
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while (right != NULL) { //remaining nodes in right gets appended to the temp list
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    return mergedNode; //returns the merged node
}

/*********************************************************************
** Function: Node* Linked_List::splitAscend(Node* head)
** Description: Splits the linked list until every list has length 1.
** Parameters: Node* head
** Pre-Conditions: The list should have at least one node.
** Post-Conditions: Every list should have length 1.
*********************************************************************/
Node* Linked_List::splitAscend(Node* head) {
    Node* ptr = head;
    Node* ptr2 = head;
    int length = 0;
    int middle = length / 2; //the middle element is halfway through the list
    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }
    ptr = head;
    if (length == 1) { //base case of recursive merge sort
        ptr->next = NULL;
        return head;
    }
    else {
        middle = length / 2; //continue to find the middle of the splitted lists (example: middle goes from 12th element to 6th, then to 3rd, then to 1st)
        for (int i = 0; i < middle - 1; i++) {
            ptr = ptr->next;
        }
        ptr2 = ptr->next;
        ptr->next = NULL;
        ptr = head;
        ptr = splitAscend(ptr); //splits the list
        ptr2 = splitAscend(ptr2); //splits the list
        length--; //continue until length is 1, which hits the base case
        return merge_ascending(ptr, ptr2); //sorts the list in ascending order
    }
    return 0;
}

/*********************************************************************
** Function: Node* Linked_List::splitDescend(Node* head)
** Description: Splits the linked list until every list has length 1.
** Parameters: Node* head
** Pre-Conditions: The list should have at least one node.
** Post-Conditions: Every list should have length 1.
*********************************************************************/
Node* Linked_List::splitDescend(Node* head) {
    Node* ptr = head;
    Node* ptr2 = head;
    int length = 0;
    int middle = length / 2; //the middle element is halfway through the list
    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }
    ptr = head;
    if (length == 1) { //base case of recursive merge sort
        ptr->next = NULL;
        return head;
    }
    else {
        middle = length / 2; //continue to find the middle of the splitted lists (example: middle goes from 12th element to 6th, then to 3rd, then to 1st)
        for (int i = 0; i < middle - 1; i++) {
            ptr = ptr->next;
        }
        ptr2 = ptr->next;
        ptr->next = NULL;
        ptr = head;
        ptr = splitDescend(ptr); //splits the list
        ptr2 = splitDescend(ptr2); //splits the list
        length--; //continue until length is 1, which hits the base case
        return merge_descending(ptr, ptr2); //sorts the list in descending order
    }
    return 0;
}

/*********************************************************************
** Function: void Linked_List::sort_ascending()
** Description: Sorts the linked list in ascending order by calling the splitAscend() 
function.
** Parameters: None
** Pre-Conditions: The list should have at least one node.
** Post-Conditions: The list should be sorted in ascending order.
*********************************************************************/
void Linked_List::sort_ascending() {
    head = splitAscend(head);
}

/*********************************************************************
** Function: void Linked_List::sort_descending()
** Description: Sorts the linked list in descending order by calling the splitDescend() 
function.
** Parameters: None
** Pre-Conditions: The list should have at least one node.
** Post-Conditions: The list should be sorted in descending order.
*********************************************************************/
void Linked_List::sort_descending() {
    head = splitDescend(head);
}

/*********************************************************************
** Function: unsigned int count_prime(Linked_List& linkedList)
** Description: Returns the number of prime numbers in the linked list. A negative 
number is never prime. 0 or 1 is not prime too.
** Parameters: Linked_List& linkedList
** Pre-Conditions: The list should have at least one value.
** Post-Conditions: The function should return the number of primes in the list.
*********************************************************************/
unsigned int count_prime(Linked_List& linkedList) {
    int numOfPrimes = 0;
    Node* ptr = linkedList.get_head();
    for (int i = 0; i < linkedList.get_length(); i++) { //loop through every value in the list
        bool prime = true;
        for (int value = 2; value < ptr->val; value++) {
            if (ptr->val % value == 0) {
                prime = false; //if the number is divisible by any number from 2 to value-1, then it is not prime
            }
        }
        if (ptr->val <= 1) { //1 is not a prime number, 0 is not a prime number, and negative numbers are not prime
            prime = false;
        }
        if (ptr->val == 2) { //2 is the only even prime number
            prime = true;
        }
        if (prime == true) { //if the number is prime, then increase the count by 1
            numOfPrimes++;
        }
        ptr = ptr->next; //go on to the next value
    }
    return numOfPrimes;
}

/****************************************************
The insert function has slightly more than 15 lines because I had to take into account 4 scenarios: inserting 
at the front of the list, at the back, somewhere in between, and if the index is out of bounds. The merge ascending, 
more descending splitAscend, and splitDescend function have more than 15 lines because I had to do a lot of steps. 
For example, for the merge functions, I had to consider if left, right, or both are not null. Then, I had to compare 
the values of left and right. Depending on the results, the pointers to the nodes will either stay in place or get swapped. 
For the split functions, I had to keep track of the length and where the middle is, and create a base case. The merge sort 
must be recursive, so that will take up lines as well. Thus, that's why the functions stated above have more than 15 lines.
*****************************************************/