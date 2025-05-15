/*
https://leetcode.com/problems/balanced-binary-tree/description/
Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example1: 
Input: root = [3,9,20,null,null,15,7]
Output: true

Example2: 
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
*/

/*
Solution approach: 
Using Top Down Recursion - O(n^2) Time and O(h) Space
A simple approach is to compute the absolute difference between the heights of the left and right subtrees for each node of the tree using DFS traversal. If, for any node, this absolute difference becomes greater than one, then the entire tree is not height-balanced.

https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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
    bool isBalanced(TreeNode* root) {
        int rootHeight = height(root);
        return rootHeight != -1 ? true : false; 
    }

    int height(TreeNode* node){
        if(node == nullptr) return 0;
        else {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);

            if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
                return -1;
            }
            /*
                 1
                / \
               2   3
                  / \
                 4   5
            Let’s compute the height step-by-step from bottom up:
            Node 4: no children → height = 0
            Node 5: no children → height = 0
            Node 3: left and right children (4, 5) both have height 0 →
            height = max(0, 0) + 1 = 1
            Node 2: no children → height = 0
            Node 1: left child = 2 → height 0; right child = 3 → height 1 →
            height = max(0, 1) + 1 = 2
            */
            return max(leftHeight, rightHeight) + 1; 
        }
    }
};

int main() {
    /*
         1
        / \
       2   3
          / \
         4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    bool result = sol.isBalanced(root);

    if (result)
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    return 0;
}