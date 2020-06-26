/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   */


// https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-with-n-keys/
class Solution {
public:
    unsigned long int binomialCoeff(int n, int k) {
        unsigned long int res = 1;
        if (k>n-k) {
            k = n-k;
        }
        for (int i=0;i<k;++i) {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    
    unsigned long int numTrees(int n) {
        unsigned long int c = binomialCoeff(2*n,n);
        return c/(n+1);
    }
};
