/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     vector<vector<int> > ans;
     vector<int> temp;
     queue<TreeNode*> q;
     if(root==NULL)
         return ans;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
     {
         TreeNode* t=q.front();
         q.pop();
         if(t==NULL)
         {
             ans.push_back(temp);
             temp.clear();
             if(q.empty())
             {
                reverse(ans.begin(),ans.end());
                 return ans;
             }
             else
             {
                 q.push(NULL);
             }
            continue;
         }
         temp.push_back(t->val);
         if(t->left!=NULL)
             q.push(t->left);
         if(t->right!=NULL)
             q.push(t->right);
     }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
