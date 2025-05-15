/*
https://leetcode.com/problems/sum-of-left-leaves/
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0

*/

/*
Solution approach: 
https://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/

Check if a node is a left leave, and sum them by applying Preorder traversal. 
Create a boolean variable that tells if the node is a left leave. 
(Node, bool left or child)

(root, false)
(9, true) => is a left child, so check if it is a leave
(20, false) => 20 is not a left child
(15, true) => 15 is a left child, cgeck if it is a leave
(7, false) => 7 is a right child
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preOrder(root, false, sum);
        return sum; 
    }

    void preOrder(TreeNode *node, bool leftChild, int &sum) {
        // if we are not in root
        if(node != nullptr) {
            //if current node is a leave and is a left child, then add its current value to the sum
            if(node->left == nullptr && node->right==nullptr && leftChild == true) {
                sum += node->val;
            }
            //If there is a left node, then recurse it by passing true as a leftchild
            if(node->left != nullptr) {
                preOrder(node->left, true, sum);
            }
            //If there is a right node, then recurse it by passing false as a leftchild
            if(node->right != nullptr) {
                preOrder(node->right, false, sum);
            }
        }
    } 
};

int main() {
    // Create the binary tree:
    //         3
    //        / \
    //       9  20
    //          / \
    //         15  7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int sum = solution.sumOfLeftLeaves(root);

    cout << "Sum of left leaves: " << sum << endl;

    // Clean up dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}