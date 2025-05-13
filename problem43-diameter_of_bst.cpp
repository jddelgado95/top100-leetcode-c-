/*
https://leetcode.com/problems/diameter-of-binary-tree/description/
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

*/

/* Solution approach: 
https://www.geeksforgeeks.org/diameter-of-a-binary-tree/

We have a function f(node) that returns the diameter of the subtree with the given node. 

How to compute the diameter? 
Diameter can be only in the left subtree or only in the right subtree.
If the diameter passe through the root node, the diameter is diameter of the right subtree + diameter of the left subtree. 

Look for the height of the node: the length of the longest path from that particular node to the leaf node. 

We are going to calculate the three possibilities (max of f(node left subtree), max (right subtree), max(root + right + left subtrees))and choose the max among them. 

*/

#include <iostream>
#include <utility> // For pair
#include <algorithm> // For max
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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p = f(root);
        return p.first;
    }
    /*
    pair<int, int> is a C++ Standard Template Library (STL) data structure that holds two values (in this case, both int types) grouped together as a single object.
    std::pair<T1, T2>
    It stores a first and a second element.
    You can access them using .first and .second.
    But a C++ function can only return one value directly. So pair<int, int> is used to package two related values together.
    A pair of two integers, for example:
    pair<int, int> p = make_pair(5, 10);
    cout << p.first << " " << p.second;  // Output: 5 10
    */
    pair<int, int> f(TreeNode *node) {
        if(node != nullptr) {
            /*left.first: diameter of the left subtree
            left.second: height of the left subtree
            right.first: diameter of the right subtree
            right.second: height of the right subtree*/
            pair<int, int> left = f(node->left);
            pair<int, int> right = f(node->right);
            //Formula of height for any tree
            int height = max(left.second, right.second) + 1;
            int diameter = max(max(left.first, right.first), left.second + right.second + 1);
            return make_pair(diameter, height);
        } else {
            return make_pair(0,0);
        }
    }
};

int main() {
    // Build a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up memory (optional for small test, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}