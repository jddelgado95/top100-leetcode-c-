/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2: 
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
*/

/* Solution approach: 

https://www.geeksforgeeks.org/count-number-of-nodes-in-a-complete-binary-tree/
Check in preorder traversal

*/

#include <iostream>
#include <climits> //for INT_MIN
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
int count = 0; // count number of nodes
    int goodNodes(TreeNode* root) {
        /*
        INT_MIN is a constant in C++ that represents the smallest (most negative) value an int can hold. It's defined in the <climits> (or <limits.h>) header file.
        */
        checkMax(root, INT_MIN);
        return count;
    }
    //max_till_parent is the current nodes parent
    void checkMax(TreeNode *node, int max_till_parent){
        if(node != nullptr) {
            int max_till_me = node->val; //asigns max till me to the current node
            if(max_till_parent == INT_MIN) { //it means that we are in the root node
                count++; 
            }  else {
                if(node->val >= max_till_parent) { // check if we are satisfying the good nodes condition
                    count++;
                }
                max_till_me = max(max_till_me, max_till_parent); //gets the max number between max_til_me and its parent. 
            }
            checkMax(node->left, max_till_me); //recurse and pass the next node to the current node, and max_till_me as parent.
            checkMax(node->right, max_till_me);
        }
    }
};


int main() {
    /*
         Example Tree:
             3
            / \
           1   4
          /   / \
         3   1   5

        Expected good nodes: 4 (3, 3, 4, 5)
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    int result = sol.goodNodes(root);
    cout << "Number of good nodes: " << result << endl;

    return 0;
}