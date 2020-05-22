/*
Problem Statement - 

Given an array of string words. Return all strings in words which is
substring of another word in any order. 
String words[i] is substring of words[j], if can be obtained 
removing some characters to left and/or right side of words[j].

Example 1 - 
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of 
"superhero".
["hero","as"] is also a valid answer.

Example 2 - 
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3 - 
Input: words = ["blue","green","bu"]
Output: []

Constraints:
* 1 <= words.length <= 100
* 1 <= words[i].length <= 30
* words[i] contains only lowercase English letters.
* It's guaranteed that words[i] will be unique.
*/

// My Solution - worked
#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubString(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        for (int i=0;i<=n-m;i++) {
            int j;
            for (j=0;j<m;j++)
                if(s2[i+j]!=s1[j])
                    break;
            if (j==m)
                return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> ans;
        int n = words.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (i==j || words[i].length()>words[j].length())
                    continue;
                if (isSubString(words[i],words[j])) {
                    ans.insert(words[i]);
                    break;
                }
            }
        }
        vector<string> v(ans.begin(),ans.end());
        return v;
    }
};

// From Discussion - almost same
// str1.find(str2) != string::npos used instead of self made function

