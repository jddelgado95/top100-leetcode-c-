/*
https://leetcode.com/problems/linked-list-cycle-ii/description/
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example2: 
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
*/

/*
Solution approach:

1) Detect cycle,. How? Using Floyd's algorithm (by creating 2 pointers, one moving faster than the other one, eventually they will meet). 

2) Detect starting point of cycle. They will meet at the beginning of the list, the idea is to use a while loop where the condition will be a start pointer != intersection pointer (a meeting point diff than the start point of the list). 

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        ListNode *intersectionpoint = nullptr;
        while(true){
            if(fast == nullptr || slow == nullptr){
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                intersectionpoint= slow;
                break;
            }
        }

        ListNode *startpoint = head;
        while(startpoint != intersectionpoint){
            startpoint=startpoint -> next;
            intersectionpoint = intersectionpoint->next;
        }
        return startpoint;
    }
};

int main(){
    // Create nodes
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Link nodes to form a cycle: 3 -> 2 -> 0 -> -4 -> back to node2
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // Cycle here
    
    Solution sol;
    ListNode *cycleStart = sol.detectCycle(node1);

    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Note: No memory cleanup here since we have a cycle; would require breaking it first.
    return 0;
}