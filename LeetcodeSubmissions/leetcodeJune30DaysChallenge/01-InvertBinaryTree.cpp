/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/*
Solution 1 - exchange left and right child pointers for every subtree, DFS
Example:

1. When tree is at root node '4', after exchange
     4
   /   \
  7     2
 / \   / \
6   9 1   3

2. Then at 2nd level at node 7
     4
   /   \
  7     2
 / \   / \
9   6 1   3

3. At leaf level, their children will return null, so no change from exchanging two null pointers.
4. Then it will go back upto root and take on the right subtree.
*/
// This can lead to recursion depth limit for large graphs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) { return NULL; }
        TreeNode *left = root->left, *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};

// Solution 2 - Level Order Traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) { return NULL; }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        return root;
    }
};
