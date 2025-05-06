/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1: 
Input: head = [1,2,2,1]
Output: true
*/

/* Solution approach 1: 
The idea is to initialize an empty stack and start traversing from the head node. Push all the nodes into the stack while traversing till end. Again traverse the linked list and compare the popped node’s data with the current node data. If both the data are not equal return false, else when stack becomes empty, it means we reach to the end node. return true, as linked list is a palindrome.

Solution approach 2: 
Using Iterative Method – O(n) Time and O(1) Space
The approach involves reversing the second half of the linked list starting from the middle. After reversing, traverse from the head of the list and the head of the reversed second half simultaneously, comparing the node values. If all corresponding nodes have equal values, the list is a palindrome.


Follow the steps below to solve the problem:

Get the size of the list. 
Reverse the 2nd half of the list
Compare the first half with the second half

Use two pointers say, fast and slow to find the middle of the list. fast will move two steps ahead and slow will move one step ahead at a time.
if list is odd, when fast->next is NULL , slow will point to the middle node.
if list is even, when fast->next->next is NULL slow will point to the middle node.
Reverse the second half of the list starting from the middle.
Check if the first half and the reversed second half are identical by comparing the node values.
Restore the original list by reversing the second half again and attaching it back to the first half.
*/

#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        // Find the point where we want to start reversing the linked list
        int n = findLength(head);
        if (n == 1){
            return true; // only one node, so it is a palindrome
        }
        int reverse_point = n/2;
        // if the list is odd, then the reverse point will be the half plus one
        if(n%2 == 1){
            reverse_point = (n/2) + 1;
        }

        // head2 is the pointing to the node where we are going to start reversing the list
        //Gets the node where the second half of the list begins.
        ListNode *head2 = findNode(head, reverse_point);
        // prev is a pointer before the reverse point
        //Gets the node just before the reversing point (needed for reconnecting after reverse).
        ListNode *prev = findNode(head, reverse_point - 1);
        reverse(head2, prev);
        //Initializes two pointers: first for the original first half, and second for the reversed second half.
        ListNode *first = head;
        ListNode *second = findNode(head, reverse_point);

        while(first != nullptr && second != nullptr){
            //Compares both halves. If a mismatch is found, it returns false. If all values match, it continues.
            if(first-> val != second->val){
                return false;
            }
            first = first->next;
            second = second -> next;
        }
        return true;
    }

    // Helper function to find the length of the list
    //Returns the node at the index (0-based). So index 2 returns the 3rd node.
    int findLength(ListNode *head) {
        int length = 0;
        ListNode *curr = head;
        while(curr != nullptr){
            curr = curr -> next;
            length++;
        }
        return length;
    }

    ListNode *findNode(ListNode *head, int index){
        int count = 0;
        ListNode *current = head;

        while(count < index) {
            current = current->next;
            count++;
        }
        return current;
    }

    // Print function for testing
    void printList(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    } 

    ListNode *reverse(ListNode *head, ListNode *prev){
        ListNode *a = head;
        ListNode *b = a->next;
        while( a != nullptr && b != nullptr){
            //Classic pointer reversal loop. Redirects each b->next to a, then moves both forward.
            ListNode *temp = b->next;
            b->next = a;
            a=b;
            a=temp;
        }
        //Connects the end of the first half (node before reversal) to the new reversed head.
        prev->next = a;
        head->next = nullptr;
        return prev;

    }
};


int main() {
    // Manually create the list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << "Is Palindrome? " << (result ? "Yes" : "No") << endl;

    // Memory cleanup (optional here but good practice)
    // In production, you'd reverse the reversed list back before deleting

    return 0;
}