#include <iostream>

#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //Type your answer here:
    ListNode* ptr = head;
    int count = 1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        count++;
    }
    if (n == count) {
        ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }
    ptr = head;
    for (int i = 0; i < count - n - 1; i++) {
        ptr = ptr->next;
    }
    ListNode* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    return head;
}
