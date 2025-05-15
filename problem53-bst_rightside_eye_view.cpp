/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
*/


/* Solution approach: 
https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
Using Level Order Traversal – O(n) Time and O(n) Space

The idea is to traverse the tree level by level and print the last node at each level (the rightmost node). A simple solution is to do level order traversal and print the last node in every level. Please refer to Right view of Binary Tree using Queue for implementation.
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


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        // there's no tree to traversal
        if(root == nullptr) {
            return result;
        }
        // queue that stores the node
        //We use a queue to do Breadth-First Search (BFS) or level-order traversal.
        //BFS visits nodes level by level, left to right.
        //We push the root node to start the process.
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            //We process each level of the tree one at a time. size tells us how many nodes are in the current level.
            int size = queue.size();

            for(int i = 0; i < size; i++){
                //We loop through all nodes at the current level:
                //Get the front node from the queue
                //Remove it from the queue
                TreeNode *node = queue.front();
                queue.pop();

                // if im in the last node of the level, the rightmost node
                /*
                i == size - 1 → you're at the last node of the level, which is the rightmost node seen from the side.
                So we add its value to the result.
                */
                if(i == size - 1){
                    result.push_back(node->val);
                }
                //Add the left child and then right child to the queue (to process in next level).
                if(node->left != nullptr) {
                    queue.push(node->left);
                }
                if(node->right != nullptr) {
                    queue.push(node->right);
                }
            }
        }
        return result;
    }

};

int main() {
    // Creating the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> rightView = sol.rightSideView(root);

    // Printing the result
    cout << "Right side view of the tree: ";
    for(int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}