/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1: 
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/

/*
Detect Loop or Cycle in Linked List: http://geeksforgeeks.org/detect-loop-in-a-linked-list/
Using Floyd’s Cycle-Finding Algorithm – O(n) Time and O(1) Space
This idea is to use Floyd’s Cycle-Finding Algorithm to find a loop in a linked list. It uses two pointers slow and fast, fast pointer move two steps ahead and slow will move one step ahead at a time.

Follow the steps below to solve the problem:
Traverse linked list using two pointers.
Move one pointer(slow) by one step ahead and another pointer(fast) by two steps ahead.
If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn’t have a loop.
*/
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // Create nodes manually
    ListNode* node1 = new ListNode(3);
    //ListNode* node2 = new ListNode(2);
    //ListNode* node3 = new ListNode(0);
    //ListNode* node4 = new ListNode(-4);

    // Link the nodes: 3 -> 2 -> 0 -> -4
    //node1->next = node2;
    //node2->next = node3;
    //node3->next = node4;

    // Create a cycle: -4 -> 2 (node2)
    //node4->next = node2; // This creates the cycle

    Solution sol;
    bool result = sol.hasCycle(node1);

    if (result) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle." << endl;
    }

    return 0;
}
