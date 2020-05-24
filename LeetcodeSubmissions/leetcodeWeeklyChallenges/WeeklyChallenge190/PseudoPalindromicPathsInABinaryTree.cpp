#include<bits/stdc++.h>
using namespace std;

/*
Given a binary tree where node values are digits from 1 to 9. A 
path in the binary tree is said to be pseudo-palindromic if at 
least one permutation of the node values in the path is a 
palindrome.
Return the number of pseudo-palindromic paths going from the root 
node to leaf nodes. 

Example 1:
Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

Example 2:
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

Example 3:
Input: root = [9]
Output: 1

Constraints:
The given binary tree will have between 1 and 10^5 nodes.
Node values are digits from 1 to 9.
*/

// Discussion 

// We count how many of each digit we got in each path in the cnt 
// array. A pseudo-palindromic path is when we have zero or one 
// digit with the odd count.

// We can track the number of odds as we increment and decrement 
// count of each digit. It makes it a bit faster than scan the 
//  array when we reach each leaf.

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
public:
int cnt[10] = {};
int pseudoPalindromicPaths(TreeNode* n, int odds = 0, int res = 0) {
    if (n != nullptr) {
        odds += ++cnt[n->val] % 2 ? 1 : -1;
        if (n->left == n->right)
            res = odds < 2 ? 1 : 0;
        else
            res = pseudoPalindromicPaths(n->left, odds) 
                + pseudoPalindromicPaths(n->right, odds);
        odds += --cnt[n->val] % 2 ? -1 : 1;
    }
    return res;
}
};