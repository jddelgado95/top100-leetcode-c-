/*
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]
*/

/*
Solution approach: 
Inorder traversal is a depth-first traversal method that follows this sequence:

Left subtree is visited first.
Root node is processed next.
Right subtree is visited last.

Algorithm :
If the root is NULL, return.
Recursively traverse the left subtree.
Process the root node (e.g., print its value).
Recursively traverse the right subtree.
*/

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorder(root, answer);
        return answer;
    }

    void inorder(TreeNode* node, vector<int>& answer){
        if(node != nullptr){
            //proces the left subtree
            inorder(node->left, answer);
            answer.push_back(node->val);
            inorder(node->right, answer);

        }
    } 
};

int main() {
    // Create a simple binary tree:
    //       1
    //        \
    //         2
    //        /
    //       3

    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node3, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, node2);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete node3;
    delete node2;
    delete root;

    return 0;
}