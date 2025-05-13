/*
https://leetcode.com/problems/path-sum/description/
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1: 
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
*/

/* Solution approach: 
https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/

Using recursion we are going to traverse BST and sum each node until we reach the null of the last leaf node. 
function(node, sum of parent)

We are appying depth-first search (DFS)

https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root, 0, targetSum);
    }

    bool f(TreeNode *node, int sumTillParent, int& targetSum){
        /*
        Base Case – Leaf Node:
        If the current node is a leaf (no children), check if the sum from root to this node equals the targetSum.
        If it does, return true; otherwise, return false
        */
        if(node->left == nullptr && node->right==nullptr){
            int sumTillMe = sumTillParent + node->val;
            if(sumTillMe == targetSum) return true;
            else return false;
        }
        /*
        Recursive Case – Internal Node:
        Calculate sumTillMe by adding the current node's value to the sum so far.
        Recursively check the left and right subtrees.
        If either side returns true, the result becomes true
        */
        else{
            bool result = false;
            int sumTillMe = sumTillParent + node->val;
            if(node->left != nullptr){
                result = result || f(node->left, sumTillMe, targetSum);
            }
            if(node->right != nullptr){
                result = result || f(node->right, sumTillMe, targetSum);
            }
            return result;
        }
    } 
};

int main() {
    /*
        Test tree:
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \      \
          7    2      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;

    bool result = sol.hasPathSum(root, targetSum);
    if (result) {
        cout << "Yes, there is a root-to-leaf path with sum " << targetSum << "." << endl;
    } else {
        cout << "No, there is no root-to-leaf path with sum " << targetSum << "." << endl;
    }

    // Cleanup (good practice)
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}