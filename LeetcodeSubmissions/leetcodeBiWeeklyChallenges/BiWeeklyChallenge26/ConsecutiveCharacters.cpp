#include<bits/stdc++.h>
using namespace std;

/*
Given a string s, the power of the string is the maximum length of 
a non-empty substring that contains only one unique character.
Return the power of the string. 

Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 
'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 
'e' only.

Example 3:
Input: s = "triplepillooooow"
Output: 5

Example 4:
Input: s = "hooraaaaaaaaaaay"
Output: 11

Example 5:
Input: s = "tourist"
Output: 1

Constraints:
1 <= s.length <= 500
s contains only lowercase English letters.
*/

// My solution - keep counting until character same, otherwise reset
class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        if (n==1) { return 1; }
        int ans = 1, power = 1;
        char prev = s[0];
        for (int i=1;i<n;i++) {
            cout<<prev<<" "<<power<<"\t";
            if (s[i]==prev) {
                power++;
            }
            else {
                ans = max(ans,power);
                power = 1;
                prev = s[i];
            }
            cout<<prev<<" "<<power<<"\n";
        }
        return max(ans,power);
    }
};