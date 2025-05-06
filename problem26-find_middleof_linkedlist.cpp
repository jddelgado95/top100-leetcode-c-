/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node

Example 1: 
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

/*
Solution approach:
https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

By Tortoise and Hare Algorithm – O(n) time and O(1) space:
We can use the Hare and Tortoise Algorithm to find the middle of the linked list. Traverse linked list using a slow pointer (slow_ptr) and a fast pointer (fast_ptr ). Move the slow pointer to the next node(one node forward) and the fast pointer to the next of the next node(two nodes forward). When the fast pointer reaches the last node or NULL, then the slow pointer will reach the middle of the linked list. 


In case of odd number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will reach the last node and in case of even number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will become NULL.

The tortoise and hare algorithm, also known as Floyd's cycle-finding algorithm, is a technique used to detect cycles in linked lists or other sequences. It uses two pointers, a "tortoise" and a "hare", that move through the sequence at different speeds. The hare moves two steps at a time, while the tortoise moves one step at a time. If a cycle exists, the hare will eventually catch up to the tortois.
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        //Once the loop ends, slow is pointing to the middle node, so return it.
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};

int main(){
    //create the nodes 1,2,3,4,5
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    // Create the link list
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution sol;

    ListNode *result = sol.middleNode(node1);

    cout << "The middle node value is: " << result->val << endl;
}