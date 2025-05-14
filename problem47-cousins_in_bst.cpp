/*

https://leetcode.com/problems/cousins-in-binary-tree/
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

Examepl1: 
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2: 
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
*/

/*
Solutions approach: 
https://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/

Using Depth First Search(preorder traversal):
The idea is to check the level of both the given node values using depth first search. If their levels are same, then check if they are children of same or different nodes. If they have same parent, then return false. else, return true.

Using a pair : <node, level> beginnging at root, <root, 0>
*/

#include<iostream>

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
    TreeNode *firstParent, *secondParent;
    int FirstLevel, SecondLevel;

    //x and y are on the same level
    //They have different parents → cousins!
    bool isCousins(TreeNode* root, int x, int y) {
        PreOrder(root, 0, NULL, x, y);
        if(FirstLevel != SecondLevel) return false;
        if(firstParent == secondParent) return false;
        return true;
    }

    void PreOrder(TreeNode *node, int level, TreeNode* parent, int x, int y){
        if(node != NULL){
            //If the current node matches x, store its level and parent.
            if(node->val == x){
                FirstLevel = level;
                firstParent = parent;
            }
            if(node->val== y){
                SecondLevel = level;
                secondParent = parent;
            }
            /*
            Recursive traversal to the left and right children:
            Pass level + 1 because we’re going one level deeper         
            Pass node as the parent for the child being explored
            */
            if(node->left != NULL){
                PreOrder(node->left, level + 1, node, x,y);
            }
            if(node->right != NULL){
                PreOrder(node->right, level + 1, node,x,y);
            }
        }
    }
};


int main() {
    /*
        Example tree:
                1
               / \
              2   3
               \
                4
        Test: Are 4 and 3 cousins? (Expected: false)

        Modify:
                1
               / \
              2   3
             /     \
            4       5
        Test: Are 4 and 5 cousins? (Expected: true)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    int x = 4, y = 5;

    if (sol.isCousins(root, x, y)) {
        cout << x << " and " << y << " are cousins." << endl;
    } else {
        cout << x << " and " << y << " are not cousins." << endl;
    }

    // Clean up
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
