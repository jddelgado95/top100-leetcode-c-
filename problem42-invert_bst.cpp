/*
https://leetcode.com/problems/invert-binary-tree/
Given the root of a binary tree, invert the tree, and return its root.
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
*/

/* Solution approach: 
Recursive Approach – O(n) Time and O(h) Space
The idea is to use recursion to traverse the tree in Post Order (left, right, root) and while traversing each node, swap the left and right subtrees.

https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

Postorder traversal is a tree traversal method that follows the Left-Right-Root order:

The left subtree is visited first.
The right subtree is visited next.
The root node is processed last.
*/

#include <iostream>
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
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }

    TreeNode* invert(TreeNode *node){
        if(node != nullptr){
            //get the values or right and left leafs
            TreeNode *left = invert(node->left);
            TreeNode *right = invert(node->right);
            // swap it
            node->left = right;
            node->right = left;
        }
        return node;
    }
};

// Helper function to print in-order traversal of the tree
void printInOrder(TreeNode* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    }
}

int main() {
    // Create the tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    cout << "Original tree (in-order): ";
    printInOrder(root);
    cout << endl;

    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);

    cout << "Inverted tree (in-order): ";
    printInOrder(invertedRoot);
    cout << endl;

    // Cleanup memory (optional for short programs, but good practice)
    delete node4;
    delete node5;
    delete node2;
    delete node3;
    delete root;

    return 0;
}