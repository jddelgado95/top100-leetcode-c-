/*
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Example 1: 
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
*/

/* Solution approach: 
Use Level order traversal. Use a map that contains the sum for each level. 

It can be optimize to use hash table.
*/

#include <iostream>
#include <map>
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
    int maxLevelSum(TreeNode* root) {
        //map<K, V> is a sorted map that stores elements as pairs: K key → V value
        map<int, int> mp;
        //A queue is a First-In-First-Out (FIFO) data structure. Elements are added at the back and removed from the front.
        queue<pair<int, TreeNode*>> q; // Stores the nodes in the pre order traversal. First: level, second: node
        //make_pair is a utility function in C++ that creates a std::pair — a simple container to hold two related values of possibly different types
        q.push(make_pair(1,root));

        while(q.size() > 0){
            //Gets the front element (the next node to be processed) without removing it. top stores the current node and its level.
            pair<int, TreeNode*> top = q.front();
            //Removes the element you just processed (which was at the front).
            q.pop();
            if(mp.find(top.first) == mp.end()){
                //Initialize level sum to 0 if it's the first time visiting that level.
                mp[top.first] = 0;
            }
            //Add the current node’s value to its level’s total sum.
            mp[top.first] = mp[top.first] + top.second->val;
            if(top.second->left != nullptr){
                //Add child nodes to the queue, incrementing the level by 1.
                q.push(make_pair(top.first + 1, top.second->left));
            }
            if(top.second->right != nullptr){
                q.push(make_pair(top.first + 1, top.second->right));
            }
        }
        //Initialize ans to level 1 (assuming level 1 exists). ans will eventually store the level with the maximum sum.
        int ans = 1;
        //Iterate over the map mp from the beginning to the end.
        for(auto it = mp.begin(); it != mp.end(); it++){
            //Check if the sum at the current level (it->second) is greater than the sum at the current ans level (mp[ans]).
            if(it->second > mp[ans]){
                //if yes, update ans to the current level number (it->first).
                ans = it->first;
            }
        }
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxLevelSum(root);
    cout << "Level with maximum sum: " << result << endl;

    return 0;
}