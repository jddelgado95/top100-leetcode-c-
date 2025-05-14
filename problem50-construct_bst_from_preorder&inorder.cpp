/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example1: 
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Preorder Traversal (Root → Left → Right)
Inorder Traversal (Left → Root → Right)
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

1. Using Pre-order traversal and Hash map - O(n) Time and O(n) Space
2. Preorder index starts at 0, pointing to the root of the whole tree.
3. You build a hash map (inorderMap) from inorder so you can find the index of any value in O(1).
4. Use the current preorder[preorderIndex] as the root.
5. Look up that root's index in the inorder array:
6. Everything to the left of that index in inorder is the left subtree
7. Everything to the right is the right subtree
8. Recursively build:
9. Left subtree using the left slice of inorder
10. Right subtree using the right slice of inorder
11. Each recursive call advances preorderIndex by 1.
*/
#include <iostream>
#include<vector>
#include <map>
#include <unordered_map>
#include <functional>
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
private: 
    int preorderIndex;
    unordered_map<int, int> inorderMap; 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        // stores the value of the node with its corresponding index, for instance here [3,9,20,15,7]. We store 3, with index 0, 9 with index 1, 20 with 2 and so on. 
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd){
        // Nothing to check, return NULL, Base case: no elements in the current inorder slice
        if(inorderStart > inorderEnd){
            return nullptr;
        }

        //  Step 1: Take current root from preorder
        int rootValue = preorder[preorderIndex];
        // create the root node
        TreeNode *root = new TreeNode(rootValue);
        //// Step 2: Find the index of the root in inorder
        int rootIndex = inorderMap[rootValue];
        // Step 3: Move to next preorder index
        preorderIndex++;
         // Step 4: Recursively build left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, inorderStart, rootIndex -1);
        root->right = buildTreeHelper(preorder, inorder, rootIndex + 1, inorderEnd);

        return root; 
    }

};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    // Print inorder traversal to verify correctness
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}