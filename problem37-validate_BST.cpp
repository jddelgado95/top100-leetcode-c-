/* 
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

https://leetcode.com/problems/validate-binary-search-tree/description/
*/

/* Solution approach: 
Using Inorder Traversal – O(n) Time and O(h) Space
The idea is to use inorder traversal of a binary search tree, in which the output values are sorted in ascending order. After generating the inorder traversal of the given binary tree, we can check if the values are sorted or not.


Note: We can avoid the use of an Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited value. If the value of the currently visited node is less than the previous value, then the tree is not BST.

https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr); // Start with no bounds
    }

    /*
    node: the current node we're checking.
    lower: the lower bound (all nodes in this subtree must be greater than this).
    upper: the upper bound (all nodes in this subtree must be less than this)
    */
    bool isValid(TreeNode* node, TreeNode* lower, TreeNode *upper){
        if(node == nullptr){ //If we've reached a nullptr, that means we're past a leaf node, and that's valid for a BST
            return true;
        }
        //If there's a lower bound and node->val is less than or equal to it → invalid.
        //If there's an upper bound and node->val is greater than or equal to it → invalid
        if((lower != nullptr && node->val <= lower->val) || (upper != nullptr && node->val >= upper->val)){
            return false;
        }
        //The upper bound becomes the current node (everything on the left must be < current)
        //The lower bound becomes the current node (everything on the right must be > current).
        return isValid(node->left, lower, node) && isValid(node->right, node, upper);
    }
};

int main() {
    // Create a valid BST
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node1, node3);

    Solution sol;
    if (sol.isValidBST(node2)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    // Clean up memory
    delete node1;
    delete node3;
    delete node2;

    return 0;
}