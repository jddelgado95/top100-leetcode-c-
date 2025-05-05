/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Exmaple 1: 
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

/*
Solution approach 1: 
Using Iterative Method – O(n) Time and O(1) Space
The idea is to reverse the links of all nodes using three pointers: 


prev: pointer to keep track of the previous node
curr: pointer to keep track of the current node 
next: pointer to keep track of the next node
Starting from the first node, initialize curr with the head of linked list and next with the next node of curr. Update the next pointer of curr with prev. Finally, move the three pointer by updating prev with curr and curr with next.
*/

/* Solution approach 2: 
Using Recursion – O(n) Time and O(n) Space
The idea is to reach the last node of the linked list using recursion then start reversing the linked list from the last node.


Follow the steps below to solve the problem:

Divide the list in two parts – first node and rest of the linked list.
Call reverse for the rest of the linked list.
Link the rest linked list to first.
Fix head pointer to NULL.

Final Effect
If you input: 1 -> 2 -> 3 -> 4

The recursive calls:
reverse(1)
  -> reverse(2)
      -> reverse(3)
          -> reverse(4) // base case, newhead = 4


Then as the stack unwinds:
3->next = 4 becomes 4->3
2->next = 3 becomes 3->2
1->next = 2 becomes 2->1
1->next = nullptr (now the tail)
*/

#include<iostream>
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
    /* Solution approach 1
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current != nullptr){
            //Save the next node in the list to a temporary pointer nextnode. This is necessary because we are about to modify current->next, and we don’t want to lose access to the rest of the list.
            ListNode* nextnode = current->next;
            //Reverse the link: instead of pointing to the next node in the list, current now points to prev, effectively reversing the direction of the pointer.
            current->next = prev;
            //Move prev one step forward, so it now points to the node we just processed (current).
            prev = current;
            //Move current one step forward to continue processing the next node in the list.
            current = nextnode;
        }
        return prev;
    */

    // Solution approache 2: 
    //Will be set to the last node during recursion.
    ListNode *newhead = nullptr;
    ListNode* reverseList(ListNode* head) {
    /* 
    If the list is not empty, call reverse(head), which will recursively reverse the list. 
    lastnode->next = nullptr; sets the old head’s next pointer to nullptr (it becomes the tail).
    Finally, return the newhead */
        if(head != nullptr){
            ListNode *lastnode = reverse(head);
            lastnode-> next = nullptr;
        }
        return newhead;
    }

    ListNode* reverse(ListNode *current){
        /*
        If current is the last node in the list:
        It becomes the new head.
        Return it so the previous node can link its next to it.
        */
        if(current->next == nullptr){
            newhead = current;
            return current;
        }
        /*
        Recursively go to the end of the list.
        On the way back:
        lastnode is the previous node (one step deeper in recursion).
        lastnode->next = current reverses the link.
        Then return current to reverse the next link in the chain.
        */
        else {
            ListNode *lastnode = reverse(current->next);
            lastnode->next = current;
            return current;
        }
    }

    // Print function for testing
    void printList(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }   
};

int main() {
    Solution sol;
    // Create a sample list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original list: ";
    sol.printList(head);

    // Reverse the list
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed list: ";
    sol.printList(reversedHead);

    return 0;
}
