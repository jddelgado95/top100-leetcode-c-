/*
https://leetcode.com/problems/merge-two-sorted-lists/description/
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

/* Solution approach
https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
[Efficient Approach] Using Iterative Merge – O(n+m) Time and O(1) Space
The idea is to iteratively merge two sorted linked lists using a dummy node to simplify the process. A current pointer tracks the last node of the merged list. We compare the nodes from both lists and append the smaller node to the merged list. Once one list is fully traversed, the remaining nodes from the other list are appended. The merged list is returned starting from the node after the dummy node. Please refer to Merge two sorted lists with O(1) auxiliary space.


Using two pointers to point to each head of the each list. 
In every iteration we're going to compare the value of the first pointer with the value of the second pointer. 
Which ever is the less value, we are going to copy it to a new linked list

*/


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

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create the two pointers
        ListNode *first = list1, *second = list2;
        //head: will point to the first node of the new merged list. tail: always points to the last node of the merged list as we build it
        ListNode *head = nullptr, *tail = nullptr;

        //Check if we have something to traverse, Keep going while there are still nodes left in either list.
        while(first != nullptr || second != nullptr){
            //Double check that we have something to traverse
            if(first != nullptr && second != nullptr){
                //Add the smaller value to the merged list.
                //Move that pointer forward (first or second).
                //tail is updated to point to the new node.
                if(first->val < second->val){
                    tail = addAtTheEnd(tail, first->val);
                    first= first->next;
                }
                else {
                    tail = addAtTheEnd(tail, second->val);   
                    second = second->next;                     
                }
            }// If One List Is Done, Use the Other: second is done, keep adding from first.                
            else if(first != nullptr){
                tail = addAtTheEnd(tail, first->val);
                first = first->next;       
            }
            else {
                tail = addAtTheEnd(tail, second->val);
                second = second->next;  
            } 
            //If this is the first node being added, set head to it. Ensures you return the full merged list starting from the beginning.
            if(head == nullptr){
                head = tail;
            }   
        }
        return head;
    }

    void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

    ListNode* addAtTheEnd(ListNode *tail, int data){
        //This dynamically creates a new ListNode object on the heap

        /*
        new ListNode creates a new node in heap memory (dynamic allocation).
        It returns a pointer to that memory.
        ListNode* newnode declares a pointer variable to store that returned address.
        So, you need the * in ListNode* newnode because you're storing a pointer — not a full ListNode object.
        */
        ListNode *newnode = new ListNode;

        //Sets the value of the new node.
        //Since it’s being added to the end, its next pointer is set to nullptr.
        newnode->val = data;
        newnode->next = nullptr; 
        //It checks if tail is not null before trying to access tail->next.
        //This prevents a segmentation fault (crash) in case someone calls the function with a nullptr tail — which could happen if the list is empty.        
        if(tail != nullptr){
            //This links the old tail node to the new node, effectively appending the new node to the end of the list.
            tail->next = newnode;
        }
        return newnode;
    }
};

int main(){
    Solution sol;

    // Create list1: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    ListNode* tail1 = list1;
    tail1 = sol.addAtTheEnd(tail1, 3);
    tail1 = sol.addAtTheEnd(tail1, 5);

    // Create list2: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    ListNode* tail2 = list2;
    tail2 = sol.addAtTheEnd(tail2, 4);
    tail2 = sol.addAtTheEnd(tail2, 6);
    ListNode* result = sol.mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    sol.printList(result);
    return 0;

}