/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1: 
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2
*/

/*
Solution approach: 
Using Recursion – O(n) Time and O(h) Space
The idea is to recursively calculate the height of the left and the right subtrees of a node and then find height to the node as max of the heights of two children plus 1. 

If the tree is empty, return -1.
Otherwise, do the following:
Get the height of the left subtree recursively, i.e., call height(node->left).
Get the height of the right subtree recursively, i.e., call height(node->right).
Compute the maximum of the heights of the left and right subtrees and add 1 to it for the current node.
height = max(height of left subtree, height of right subtree) + 1.
Return the height.

f(node) = max(f(node.left)+1), f(node.right)+1)

     1
    / \
   2   3
  /
 4
The depths are:

Node 4 → 1

Node 2 → 2 (max of left=1, right=0) + 1

Node 3 → 1

Node 1 → max(2, 1) + 1 = 3

So the function returns 3.

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        else {
            //While returning back up, keep calculating the height by taking the max of both subtrees and adding 1.
            return max(maxDepth(root->left) + 1, maxDepth(root->right)+1);
        }
    }
};

int main() {
    // Construct this binary tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Maximum depth of the tree is: " << depth << endl;

    // Clean up allocated memory
    delete node4;
    delete node2;
    delete node3;
    delete root;

    return 0;
}