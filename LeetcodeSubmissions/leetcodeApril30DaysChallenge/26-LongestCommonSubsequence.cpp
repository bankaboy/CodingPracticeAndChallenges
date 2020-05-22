/*
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters(can be none) 
deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while 
"aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:
1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/



// Recursion
class Solution {
public:
    int lcsUtil (string X, string Y, int m, int n) {
        if (m == 0 || n == 0)  
            return 0;  
        if (X[m-1] == Y[n-1])  
            return 1 + lcsUtil(X, Y, m-1, n-1);  
        else
            return max(lcsUtil(X, Y, m, n-1), lcsUtil(X, Y, m-1, n));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return lcsUtil(text1,text2,text1.size(),text2.size());
    }
};

// Dynammic Programming
class Solution {
public:
    int lcsUtil (string X, string Y, int m, int n) {
        int L[m + 1][n + 1];  
        int i, j;  
        for (i = 0; i <= m; i++)  {  
            for (j = 0; j <= n; j++)  {  
                if (i == 0 || j == 0)  
                    L[i][j] = 0;  
                else if (X[i - 1] == Y[j - 1])  
                    L[i][j] = L[i - 1][j - 1] + 1;  
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
            }  
        }  
        return L[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return lcsUtil(text1,text2,text1.size(),text2.size());
    }
};
