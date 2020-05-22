/*
Maximum Score After Splitting String 

Given a string s of zeros and ones, return the maximum score after 
splitting the string into two non-empty substrings (i.e. left 
substring and right substring).
The score after splitting a string is the number of zeros in the 
left substring plus the number of ones in the right substring.

Example 1:
Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

Example 3:
Input: s = "1111"
Output: 3

Constraints:
2 <= s.length <= 500
The string s consists of characters '0' and '1' only.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// My Solution 
/* Keep track of last position till which there are 
   continuous zeroes as if we break after that point we will 
   compromise the score given by 1s in the right string.
   return score-1 if only 0s or 1s as it is mandatory to split the
   string once. Failed on case 
Input:
"01001"
Output:
3
Expected:
4
Stdout:
1 -> Break Point
0 1001 -> Left and right string
It would be better to break at last 0
*/
class Solution {
public:
    int maxScore(string s) {
        string::iterator it = s.begin();
        int pos = 0, score =0, n=s.size();
        while(it!=s.end()) {
            if (*it=='0')
                pos++;
            else if (*it=='1')
                break;
            it++;
        }
        cout<<pos;
        string left = s.substr(0,pos);
        string right = s.substr(pos);
        cout<<"\n"<<left<<" "<<right;
        for (char c:left) {
            if (c=='0')
                score++;
        }
        for (char c:right) {
            if (c=='1')
                score++;
        }
        if (pos==0 || pos==n)
            return score-1;
        return score;
    }
};

// Discussion

class Solution {
public:
    int maxScore(string s) {
        int r0(0), r1(0), l0(0), l1(0);
        
        for (const char& c: s)
            c == '0' ? r0++ : r1++;
        
        s.pop_back();
        int ans(0);
        
        for (const char& c: s) {
            if (c == '0') {
                l0++;
                r0--;
            } else {
                l1++;
                r1--;
            }
            ans = max(ans, l0 + r1);
        }
        
        return ans;
    }
};
