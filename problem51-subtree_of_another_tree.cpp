/*
https://leetcode.com/problems/subtree-of-another-tree/
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1: 
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

Check the subroot in the original tree, and from that, start comparing leafs. If there is a missmatch, then the subroot is not from that tree. 

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //If the main tree is empty, it can't contain any subtree — return false.
        if(root == nullptr){
            return false;
        }
        //If the tree rooted at the current root node is exactly the same as subRoot, then we found the match — return true.
        if(isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode * t1, TreeNode* t2){
        //Both trees are empty — they're identical.
        if(t1 == nullptr && t2 == nullptr) {
            return true;
        }
        //One tree is empty and the other isn’t — can’t be identical.
        if(t1 == nullptr || t2 == nullptr){
            return false;
        }
        //Values at the current nodes don’t match — trees aren’t identical.
        if(t1->val != t2->val){
            return false;
        }
        //Check if both left and right subtrees are also identical.
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
};

int main() {
    // Construct main tree:
    //       3
    //      / \
    //     4   5
    //    / \
    //   1   2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Construct subtree:
    //     4
    //    / \
    //   1   2
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution solution;
    bool result = solution.isSubtree(root, subRoot);

    if (result) {
        cout << "subRoot is a subtree of root." << endl;
    } else {
        cout << "subRoot is NOT a subtree of root." << endl;
    }

    return 0;
}
