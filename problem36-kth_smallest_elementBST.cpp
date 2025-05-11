/* 
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
*/

/* Solution approach: 
Using In-Order traversal – O(k) Time and O(h) Space
The idea is to traverse the binary search tree using in-order traversal while maintaining the count of nodes traversed. If the node count becomes equal to k, then return the node.

Inorder Traversal
Inorder traversal visits the node in the order: Left -> Root -> Right
*/
#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
//A struct is like a class, but members are public by default.
struct TreeNode {
    int val; //stores the value of the node 
    //pointers to the node's left and right children
    TreeNode *left;
    TreeNode *right;
    //Default constructor: creates a node with val = 0, and left and right pointers set to nullptr (no children).
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //Single-value constructor: creates a node with a specific value x, and no children.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //Full constructor: allows setting the value x, and explicitly assigning the left and right child nodes.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
TreeNode* leftChild = new TreeNode(2);
TreeNode* rightChild = new TreeNode(3);
TreeNode* root = new TreeNode(1, leftChild, rightChild);

    1
   / \
  2   3
*/

class Solution {
public:
    int count = 0; //holds the k count
    int answer = -1; //returns -1 if the k value can not be found
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return answer;    

    }

    void inOrder(TreeNode* node, int k){
        if(node->left != nullptr){
            inOrder(node->left, k);
        }
        count++;
        if(count == k) {
            answer = node->val;
            return;
        }
        if(node->right != nullptr){
            inOrder(node->right, k);
        }
    }
};

int main() {
    // Construct the BST:
    //         5
    //        / \
    //       3   6
    //      / \
    //     2   4
    //    /
    //   1

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2, n1, nullptr);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(3, n2, n4);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* root = new TreeNode(5, n3, n6);

    int k = 3;
    Solution sol;
    int result = sol.kthSmallest(root, k);

    cout << "The " << k << "rd smallest element is: " << result << endl;

    // Clean up memory
    delete n1;
    delete n2;
    delete n4;
    delete n3;
    delete n6;
    delete root;

    return 0;
}