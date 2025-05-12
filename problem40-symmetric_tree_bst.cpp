/*
https://leetcode.com/problems/symmetric-tree/
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example 1: 
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2: 
Input: root = [1,2,2,null,3,null,3]
Output: false
*/

/*
Solution approach: 
Using Recursion – O(n) Time and O(h) Space
The idea is to recursively compare the left and right subtrees of the root. For the tree to be symmetric, the root values of the left and right subtrees must match, and their corresponding children must also be mirrors. 

If right child == left child
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
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode *f1, TreeNode *f2){
        // Theres nothing to compare, so they're symmetric
        if(f1 == nullptr && f2 == nullptr) return true;
        //No symmetric, either both are null or neither is null
        if(f1 == nullptr || f2 == nullptr) return false;
        //return true if val of f1 and f2 are the same, and true by comparing the left nodes with right nodes, and right nodes with left nodes. 
        return f1->val == f2->val && isSym(f1->left , f2->right) && isSym(f1->right, f2->left);
    }
};

int main() {
    /*
        Construct this symmetric binary tree:
               1
             /   \
            2     2
           / \   / \
          3   4 4   3
    */
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(4);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(2, n1, n2);
    TreeNode* n6 = new TreeNode(2, n3, n4);
    TreeNode* root = new TreeNode(1, n5, n6);

    Solution sol;
    bool result = sol.isSymmetric(root);

    cout << (result ? "The tree is symmetric." : "The tree is not symmetric.") << endl;

    // Cleanup
    delete n1; delete n2; delete n3; delete n4;
    delete n5; delete n6; delete root;

    return 0;
}