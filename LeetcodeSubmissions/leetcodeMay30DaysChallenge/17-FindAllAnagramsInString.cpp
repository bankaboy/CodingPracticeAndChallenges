/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 
20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// Try 1 - Sliding window over s and compare counts of letters with p
class Solution {
    bool compare(char arr1[], char arr2[]) { 
        for (int i=0; i<26; i++) 
            if (arr1[i] != arr2[i]) 
                return false; 
        return true; 
    } 
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> ans;
        if (n<m) return ans;
        char countP[26] = {0}, countTW[26] = {0};
        for(int i=0;i<m;i++) {
            (countP[p[i]-'a'])++;
            (countTW[s[i]-'a'])++;
        }
        for (int i = m; i < n; i++) { 
            if (compare(countP, countTW)) {ans.push_back((i-m));}
            (countTW[s[i]-'a'])++; 
            countTW[s[i-m]-'a']--; 
        } 
        if (compare(countP, countTW)) { ans.push_back((n-m)); } 
        return ans;
    }
};

// Cleaner solution -  Did not know we could directly compare vectors, compare function not needed
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0), sv(26,0), res;
        if(s.size() < p.size())
           return res;
        for(int i = 0; i < p.size(); ++i) {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i)  {
            ++sv[s[i]-'a'];
            --sv[s[i-p.size()]-'a']; 
            if(pv == sv) {res.push_back(i-p.size()+1); }
        }
        return res;
    }
};
