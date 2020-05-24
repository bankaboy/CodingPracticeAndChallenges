#include<bits/stdc++.h>
using namespace std;

// Solution 1 - Realized that substrings need not be continuous

class Solution {
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int count = 0, res = 0; 
        for (int i = 0; i <= s.length(); i++)  { 
  
            // Increment current count if s[i] is vowel  
            if (isVowel(s[i]) && count<k)  
                count++;      
      
            else { 
            // check previous value is greater then or not 
                res = max(res, count); 
                count = 0; 
            } 
        } 
    return res;
    }
};

// Solution 2 - TLE
class Solution {
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int vowelCount(string s) {
        int count = 0;
        for(char c:s) {
            if (isVowel(c)) {
                count++;
            }
        }
        return count;
    }
public:
    int maxVowels(string s, int k) {
        int count = 0, res = 0; 
        int len = s.length();
        for (int j=0;j<len-k+1;j++) {
            string substring = s.substr(j,k);
            // cout<<substring<<"\n";
            count = vowelCount(substring);
            res = max(res,count);
        } 
    return res;
    }
};

// Discussion
// Just a simple sliding window pattern: count vowels moving in and out of window, and keep track of the maximum.
class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        
        int max_vow = 0;
        
        for (int i = 0, cur_vow = 0; i < s.size(); ++i) {
            // add letter to end of window
            cur_vow += vowels[s[i] - 'a'];
            
            if (i >= k) {
                // this removes the letter at the start of the 
                // window
                cur_vow -= vowels[s[i - k] - 'a'];
            }
                
            max_vow = max(cur_vow, max_vow);
        }
        
        return max_vow;
    }
};