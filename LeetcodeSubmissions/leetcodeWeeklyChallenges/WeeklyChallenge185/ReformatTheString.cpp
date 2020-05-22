/*
Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

Example 1:
Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.

Example 2:
Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.

Example 3:
Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.

Example 4:
Input: s = "covid2019"
Output: "c2o0v1i9d"

Example 5:
Input: s = "ab123"
Output: "1a2b3"

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// My try 
class Solution {
    int findChar(string s) {
        int n = s.length();
        for (int i=0;i<n;i++) {
            if(isalpha(s[i])) 
                return i;            
        }
        return -1;
    }
    int findNumber(string s) {
        int n = s.length();
        for (int i=0;i<n;i++) {
            if(isdigit(s[i])) 
                return i;            
        }
        return -1;
    }
public:
    string reformat(string s) {
        string ans;
        int type = 0; // to maintain last added type, 1 - alphabet, 0 - digit
        int idx;
        if (isalpha(s[0])) {
            ans.push_back(s.front());
            s.erase(s.begin());
            type=1;
        }            
        if (isdigit(s[0])) {
            ans.push_back(s.front());
            s.erase(s.begin());
            type=0;
        }
        while(!s.empty()) {
            if (type==1) {
                idx = findNumber(s);
                if (idx==-1 && s.size()>1)
                    return "";
                ans.push_back(s[idx]);
                s.erase(idx);
                type = 0;
            }
            if (type==0) {
                idx = findChar(s);
                if (idx==-1 && s.size()>1) 
                    return "";
                ans.push_back(s[idx]);
                s.erase(idx);
                type = 1;
            }
        }
        return ans;
    }
};

// Discussion - 

class Solution {
public:
    string reformat(string s) {
        int c1(0), c2(0);
        unordered_map<char, int> cnts;
        
        for (const char& c: s) {
            isalpha(c) ? c1++ : c2++;
            cnts[c]++;
        }
        
        if (abs(c1 - c2) > 1) return "";
        
        string ans;
        for (int i = 0; i < s.length(); ++i) {
		    // if c1 >= c2, "letter-number-letter..."
			// otherwise, "number-letter-number..."
            string t = (i % 2) ^ (c1 >= c2) ? "az" : "09";
            for (char c = t[0]; c <= t[1]; ++c) {
                if (cnts[c]) {
                    cnts[c]--;
                    ans += c;
                    break;
                }
            }
        }
        
        return ans;
    }
};