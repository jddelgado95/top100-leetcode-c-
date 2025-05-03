/*
https://leetcode.com/problems/intersection-of-two-linked-lists/description/

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

Example: 
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
*/

/*
Solution approach: 
[Expected Approach – 1] Using difference in node counts – O(m + n) Time and O(1) Space
https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

A common node in two linked lists points to the same memory location. When two linked lists merge, they share the exact same node, meaning that from the merging point onwards, both lists are identical in terms of nodes and memory addresses. If two nodes from different linked lists are considered "common," it implies that they are the same node residing at the same memory address. Comparing the memory addresses of the nodes is a way to check if they are the same.

*/

/**
 * 
 * ListNode is a common user-defined struct (or class) in C++ used to represent a node in a singly linked list.

A typical definition looks like this:
struct ListNode {
    int val;            // Value stored in the node
    ListNode *next;     // Pointer to the next node

    // Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};
Explanation:
int val: stores the data or value in the node.
ListNode* next: a pointer to the next node in the linked list.
The constructor ListNode(int x) initializes a node with the value x and sets next to nullptr.
This structure allows you to build a chain of nodes like this:
head -> [1] -> [2] -> [3] -> nullptr

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = findLength(headA);
        int n = findLength(headB);

        // Create two pointers, for each list
        ListNode *fp = headA, *sp = headB;
        // If the second list is shorter than the first one, then move the pointer 
        //If one list is longer, move the pointer on the longer list forward so that both pointers have the same number of nodes left to traverse.
        if (m <= n){
            for(int i=0; i<n-m;i++){
                sp = sp->next;
            }

        }
        else {
            for(int i=0; i<m-n;i++){
                fp = fp-> next;
            }
        }
        /*Now both pointers move one step at a time.
        If they meet (sp == fp), it means there's an intersection — return that node.
        If the loop ends, return NULL (no intersection).*/
        while(sp != nullptr){
            if(sp == fp){
                return fp;
            }
            sp = sp->next;
            fp = fp->next;
        }
        return nullptr;
    }
private:
    // Helper function to find the length of the list
    int findLength(ListNode *head) {
        int length = 0;
        ListNode *curr = head;
        while(curr != nullptr){
            curr = curr -> next;
            length++;
        }
        return length;
    }
};

int main() {
    // Create shared part of the list
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);

    if (result != nullptr) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    // Optional: free memory if needed
    // (Only needed if you're managing memory manually or in production code)

    return 0;
}