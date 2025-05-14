/*
https://leetcode.com/problems/path-sum-ii/description/

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []
*/

/* Solution approach: 
Apply pre-order traversal again.

Start traversal from 5, and sum while traversing. 
When moving from one node to the other: [node sums, [array of nodes]]

*/
#include <vector>
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
    vector<vector<int>> answer;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        preOrder(root, 0, path, targetSum);
        return answer;
    }

    void preOrder(TreeNode* node, int sumTillParent, vector<int>& pathTillParent, int targetSum){
        if(node !=nullptr){
            int sumTillMe = sumTillParent + node->val;
            //Add the current node’s value to the path we're building.
            pathTillParent.push_back(node->val);
            /*
            Check if:
            It's a leaf node, and
            The path sum equals the target
            If so, copy the path and add it to the final answer.
            */
            if(node->left == nullptr && node->right == nullptr && sumTillMe == targetSum){
                //Copy pathTillParent into a new vector and store it in answer (to avoid reference-related bugs when the vector backtracks later).
                vector<int> path;
                for(int num : pathTillParent) {
                    path.push_back(num);
                }
                answer.push_back(path);
            }
            // Recurse Left and Right: Visit children recursively, continuing the path and updated sum.
            if (node->left != NULL){
                preOrder(node->left, sumTillMe, pathTillParent, targetSum);
            }
            if (node->right != NULL){
                preOrder(node->right, sumTillMe, pathTillParent, targetSum);
            }
            // Important step: remove the last added node before returning so the parent call continues with the correct path state.
            pathTillParent.pop_back();
        }
    }
};

int main() {
    /*
        Sample tree:
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \     / \
          7    2   5   1

        Target sum = 22
        Expected paths:
        - 5→4→11→2
        - 5→8→4→5
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    cout << "Paths summing to " << targetSum << ":\n";
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up (to avoid memory leaks)
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}