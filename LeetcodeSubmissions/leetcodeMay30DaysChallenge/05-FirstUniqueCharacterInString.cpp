/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/



/* 
Store all the letter and count in a hashmap.
Iterate over string and return the first index whose character frequency is 1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        for (int i=0;i<n;i++) {
            char c = s[i];
            if (mp.find(c)==mp.end()) {
                mp[c] = 1;
            } else {
                mp[c]+=1;
            }
        }
        
        for(int i=0;i<n;i++) {
            if (mp[s[i]]==1) {
                return i;
            }
        }
        return -1;
    }
};
