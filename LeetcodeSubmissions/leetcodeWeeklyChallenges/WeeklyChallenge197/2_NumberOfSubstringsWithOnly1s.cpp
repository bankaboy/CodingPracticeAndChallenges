/*
Given a binary string s (a string consisting only of '0' and '1's).

Return the number of substrings with all characters 1's.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.
Example 4:

Input: s = "000"
Output: 0
 

Constraints:

s[i] == '0' or s[i] == '1'
1 <= s.length <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;

// Attempt 1 - Brute force 
// keep increasing "1" in the subsrting and keep searching
class Solution {
public:
    int countFreq(string &pat, string& txt) {
        int M = pat.length(); 
        int N = txt.length(); 
        int res = 0; 
    
        /* A loop to slide pat[] one by one */
        for (int i = 0; i <= N - M; i++) {  
            /* For current index i, check for pattern match */
            int j; 
            for (j = 0; j < M; j++) 
                if (txt[i+j] != pat[j]) 
                    break; 
       
            // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) { 
                res++; 
                j = 0; 
            } 
        } 
        return res;
    }
    
    int numSub(string s) {
        string base = "1";
        int n = s.size(), res = 0;
        for(int i=0;i<n;i++) {
            res += countFreq(base,s);
            base = base+"1";
        }
        return res;
    }
};


// Attempt 2 - Wrong answer
class Solution {
public:
    void computeLPSArray(string& pat, int m, vector<int>& lps) {
        int len=0, i=1;
        lps[0] = 0;
        while (i<m) {
            if (pat[i]==pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len!=0) {
                    len = lps[len-1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
    
    int KMPSearch(string& pat, string& txt) {
        int m = pat.length();
        int n = txt.length();
        vector<int> lps(m);
        int j = 0;
        computeLPSArray(pat, m, lps);
        
        int i=0;
        int res = 0;
        int next_i = 0;
        
        while (i<n) {
            if (pat[j]==txt[i]) {
                j++;
                i++;
            }
            if (j==m) {
                j = lps[j-1];
                res++;
                
                if (lps[j]!=0)
                    i = ++next_i;
                j = 0;
            } 
            else if (i<n && pat[j]!=txt[i]) {
                if (j!=0)
                    j = lps[j-1];
                else 
                    i = i+1;
            }
        }
        return res;
    }
    
    int numSub(string s) {
        string base = "1";
        int n = s.size(), res = 0;
        for(int i=0;i<n;i++) {
            int x = KMPSearch(base,s);
            cout<<x<<" ";
            res += x;
            base = base+"1";
        }
        return res;
    }
};

// Attempt 3 - Hoping inbuilt functions are faster
class Solution {
public:
    int substrPosition(string str, string sub_str) {
        int flag = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.substr(i, sub_str.length()) == sub_str) {
                flag++;
            }
        }
        return flag;
    }
    
    int numSub(string s) {
        string base = "1";
        int n = s.size(), res = 0;
        for(int i=0;i<n;i++) {
            int x = substrPosition(s,base);
            cout<<x<<" ";
            res += x;
            base = base+"1";
        }
        return res;
    }
};

// Discussion 

class Solution {
public:
    int numSub(string s) {
        int res = 0, count = 0, mod = 1e9 + 7;
        for (char c: s) {
            count = c == '1' ? count + 1 : 0;
            res = (res + count) % mod;
        }
        return res;
    }
};