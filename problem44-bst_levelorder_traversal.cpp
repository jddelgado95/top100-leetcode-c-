/*
https://leetcode.com/problems/binary-tree-level-order-traversal/description/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1: 
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
*/

/* Solution approach: 

https://www.geeksforgeeks.org/level-order-tree-traversal/

Using Queue (Iterative) – O(n) time and O(n) space
Looking at the examples, it’s clear that tree nodes need to be traversed level by level from top to bottom. Since the tree structure allows us to access nodes starting from the root and moving downward, this process naturally follows a First-In-First-Out (FIFO) order. So we can use queue data structure to perform level order traversal.

Store a pair: 
(node, level), so for root for instance would be: (3,1)
*/
#include <iostream>
#include <vector>
#include <queue>
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

//This code is part of a level order traversal (also called breadth-first traversal) of a binary tree, where each level's values are grouped and stored in a 2D vector answer.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) {
            return answer;
        }
        // Pair for node and level
        queue<pair<TreeNode* , int>> q;
        //Pass root node and its level 1
        q.push(make_pair(root, 1));

        while(q.size() > 0){
            //Retrieve the front node and its level, then remove it from the queue.
            pair<TreeNode*, int> p = q.front();
            q.pop();
            //Extract the node and level:
            TreeNode* currentNode = p.first; 
            int currentLevel = p.second;

            // Check if list for created level is created or not, If answer doesn’t already have a list for this level, create one. For example, if you're processing level 3 and answer only has two lists (for levels 1 and 2), you create a new one.
            if(answer.size() < currentLevel){
                vector<int> vec; 
                answer.push_back(vec);
            }
            //Adds the current node’s value to the latest level list in answer
            //answer[answer.size() - 1] Accesses the last inner vector, i.e., the vector representing the current level.
            answer[answer.size() - 1].push_back(currentNode->val);
            //Push children to the queue with incremented level:
            if(currentNode->left){
                q.push(make_pair(currentNode->left, currentLevel + 1));
            }
            if(currentNode->right){
                q.push(make_pair(currentNode->right, currentLevel + 1));
            }
        }
        return answer;
    }

};

// Helper function to print level order result
void printLevelOrder(const vector<vector<int>>& levels) {
    for (int i = 0; i < levels.size(); ++i) {
        cout << "Level " << i + 1 << ": ";
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Build this tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    printLevelOrder(result);

    // Clean up memory (good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}