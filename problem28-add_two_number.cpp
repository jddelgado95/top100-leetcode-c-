/*
https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1: 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
*/

/* Solution approach
By storing sum on the longer list – O(m + n) Time and O(1) Space
The idea is to iterate over both the linked list simultaneously and instead of creating a new linked list to store the result, we can store the result in the longer list itself. If we are left with some carry after traversing both the linked list, we can create a new node and append it at the end of the longer linked list.

https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-list/
*/


#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // l1 and l2 are the starting point of the linked list
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Pointing to NULL, which means is pointing beyond the linked list
        ListNode *head = nullptr;
        // Always points to the last pointer of the list
        ListNode *current = head;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            //If l1 still has a node, add its value to sum and move l1 to its next node.
            if( l1 != nullptr){
                sum += l1 -> val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                sum += l2 -> val;
                l2 = l2->next;
            }
            /*
            handling addition with carry-over, This logic mirrors the column-wise addition we do by hand:
               7
            +  5
            ---
            12  → write 2, carry 1
            */
            sum += carry;
            //Extracts the digit to be stored in the current node.
            int val = sum % 10;
            //Extracts the carry-over for the next iteration.
            carry = sum / 10; 
            //If this is the first node, create it and assign it to both head and current.
            if(current == nullptr){
                head = new ListNode(val);
                current = head;
            //Otherwise, add a new node at the end (current->next) and move current forward.
            } else {
                current->next = new ListNode(val);
                current = current -> next;
            }

        }
        //f there is any carry left (like from 9 + 1 = 10), we create a final node to hold it.
        if(carry > 0){
            current->next = new ListNode(carry);
        }
        return head;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Manually create the first list: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Manually create the second list: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Compute the sum: 342 + 465 = 807, result should be 7 -> 0 -> 8
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printList(result);

    return 0;
}