/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1: 
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]


Follow up: Could you do this in one pass?
*/

/* 
Solution approach:
https://www.geeksforgeeks.org/delete-nth-node-from-the-end-of-the-given-linked-list/

Using Fast and Slow Pointers – O(n) time and O(1) space
The idea is to use two pointers, fast and slow, to traverse the linked list. The fast pointer is moved n steps ahead first, and then both pointers are moved together until fast reaches the end. At this point, slow will be just before the node to be deleted, allowing us to remove the nth node from the end efficiently in a single pass.

Slow = 1
Fast = 1
n = 4

fast = 2
fast = 3
fast = 4
fast = 5
slow = 2
fast = NULL 
slow = 3

Using the two-pointer approach (fast and slow), by the time fast reaches the end of the list, slow points to the node just before the one you want to remove.

So now, you have this situation (example):
1 → 2 → 3 → 4 → 5
          ↑    ↑
        slow  slow->next (4)

slow->next is pointing to the node we want to remove (in this case, 4)
slow->next->next is pointing to the node after the one we're removing (in this case, 5)

slow->next = slow->next->next;
skips the node 4 by:
disconnecting it from the list, and
linking node 3 directly to node 5.

The result is: 1 → 2 → 3 → 5
Node 4 is now unreachable and will be cleaned up (freed in C++ if needed).
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;

        //Move fast N + 1 steps:
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if(fast == nullptr){
            return head->next;
        }

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        //Remove the node
        slow->next = slow->next->next;
        return head;
    }
};

// Utility to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create the list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;  // Remove the 2nd node from end (which is 4)
    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    // Output the modified list
    printList(head);

    return 0;
}