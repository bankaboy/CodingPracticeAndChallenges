#include<bits/stdc++.h>
using namespace std;

/*
Problem - 
Given two strings: s1 and s2 with the same size, check if some 
permutation of string s1 can break some permutation of string s2 or 
vice-versa (in other words s2 can break s1).
A string x can break string y (both of size n) if x[i] >= y[i] 
(in alphabetical order) for all i between 0 and n-1.

Example 1:
Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".

Example 2:
Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.

Example 3:
Input: s1 = "leetcodee", s2 = "interview"
Output: true

Constraints:
s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.
*/

/* My solution 
Since we have to check for all permutations. Check a character in
string 1 against all characters in string 2.
*/
/*
Problem - 
Comparing each character against all characters of other string.
Therefore it will return true even if 1 char is less in string 2.
Need to remove a char from second string after comparing it
*/
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool ans = true;
        for (char c1:s1) {
            for (char c2:s2) {
                if (c1>=c2) {
                    cout<<"Comparison 1\n";
                    ans = true;
                    break;
                }
                else {
                    cout<<"Iteration failed\n";
                    ans = false;
                } 
            }
            if (ans==false)
                return false;
        }
        if (ans==true) // the case runs one way, then we can return true
            return true;
        
        for (char c2:s2) {
            for (char c1:s1) {
                if (c2>=c1) {
                    ans = true;
                    break;
                }        
                else 
                    ans = false;
            }
            if (ans==false)
                return false;
        }
        
        return ans;
    }
};

// Second Idea - Still wrong answer
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool ans = true;
        string s11=s1, s22=s2;
        for (string::iterator it1=s11.begin();it1!=s11.end();it1++) {
            for (string::iterator it2=s22.begin();it2!=s22.end();it2++) {
                if (*it1>=*it2) {
                    s11.erase(it1);
                    s22.erase(it2);
                    ans = true;
                    break;
                }
                else {
                    ans = false;
                } 
            }
            if (ans==false)
                return false;
        }
        if (ans==true) // the case runs one way, then we can return true
            return true;
        
        for (string::iterator it1=s22.begin();it1!=s22.end();it1++) {
            for (string::iterator it2=s11.begin();it2!=s11.end();it2++) {
                if (*it1>=*it2) {
                    s11.erase(it1);
                    s22.erase(it2);
                    ans = true;
                    break;
                }
                else {
                    ans = false;
                } 
            }
            if (ans==false)
                return false;
        }
 
        
        return ans;
    }
};


// Discussion - 

class Solution {
public:
    bool canBreak(vector<int> v1, vector<int> v2) {
        int i(25), j(25);
        while (true) {
            while (i >= 0 && v1[i] == 0) i--;
            while (j >= 0 && v2[j] == 0) j--;
            if (i < 0 || j < 0) return true;
            if (i > j) return false;
            int x = min(v1[i], v2[j]);
            v1[i] -= x;
            v2[j] -= x;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> letters1(26), letters2(26);
        for (const char& c: s1) letters1[c - 'a']++;
        for (const char& c: s2) letters2[c - 'a']++;
        return canBreak(letters1, letters2) || canBreak(letters2, letters1);
    }
};
