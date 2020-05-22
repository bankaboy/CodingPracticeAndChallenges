/*
Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value 
< node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays 
the value of the node first, then traverses node.left, then traverses node.right.) 

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* constructTreeUtil( vector<int> pre, int* preIndex, int key,  
                                int min, int max, int size )  {  
        if( *preIndex >= size )  
            return NULL;  
        TreeNode* root = NULL;  
        if( key > min && key < max ) {  
            root = new TreeNode ( key );  
            *preIndex = *preIndex + 1;            
            if (*preIndex < size)  {  
                root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],  
                                        min, key, size );  
                root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],  
                                        key, max, size );  
            }  
        }  
        return root;  
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size(), preIndex = 0;
        return constructTreeUtil ( preorder, &preIndex, preorder[0], INT_MIN,  
                            INT_MAX, size );
    }
};

class Solution2 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return NULL;
        int root_value = preorder[0];
        vector<int> smaller, greater;
        for (int i=1;i<(int)preorder.size();i++) {
            if (preorder[i]<root_value)
                smaller.push_back(preorder[i]);
            else
                greater.push_back(preorder[i]);
        }
        TreeNode* root = new TreeNode(root_value);
        root->left = bstFromPreorder(smaller);
        root->right = bstFromPreorder(greater);
        return root;
    }
};

class Solution3 {
    TreeNode* helper(const vector<int>& preorder, int& id, int limit) {
        if (id==preorder.size() || preorder[id]>limit) {
            return NULL;
        }
        int root_value = preorder[id];
        TreeNode* root = new TreeNode(root_value);
        id++;
        root->left = helper(preorder,id,root_value);
        root->right = helper(preorder,id,limit);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id = 0;
        return helper(preorder,id,INT_MAX);
    }
};
