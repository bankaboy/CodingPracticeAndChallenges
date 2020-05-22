#include<bits/stdc++.h>
using namespace std;

/*
Given a binary tree root, a node X in the tree is named good if in 
the path from root to X there are no nodes with a value greater 
than X.
Return the number of good nodes in the binary tree.

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good. 

Constraints:
The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
*/

/* My solution - 
f value of node is >= max of current path, add to count. Then call 
the left/right with max of val and maxVal
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // if value of node is >= max of current path, add to count. Then call the left/right with max of val and maxVal
    int returnCount(TreeNode* node, int maxVal) {
        if (node==NULL) { return 0; }
        int count = 0;
        if (node->val >= maxVal) {
            count += 1;
        }
        count += returnCount(node->left, max(node->val,maxVal));
        count += returnCount(node->right, max(node->val,maxVal));
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        if (root->left==NULL && root->right==NULL) { return 1; } // base case , root is always good
        return returnCount(root, root->val);
    }
};

// Discussion - One Liner, same Logic
class Solution {
public:
    int goodNodes(TreeNode* root, int val=INT_MIN) {
        return root == nullptr ? 0 : (val <= root->val) 
        + goodNodes(root->left, max(root->val, val))
            + goodNodes(root->right, max(root->val, val));
    }
};