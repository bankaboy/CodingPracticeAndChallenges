/*
Problem statement - 

Given a string s and an integer k. You should construct k non-empty
palindrome strings using all the characters in s.
Return True if you can use all the characters in s to construct k 
palindrome strings or False otherwise

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
*/

#include<iostream>
#include<vector>
using namespace std;

bool canConstruct(string s, int k) {
    if(s.size()<k){
        return false;
    }
    vector<int> v(26,0);
    for(auto& c:s){
        v[c-'a']++;
    }
    int odds=0;
    for(int i=0;i<v.size();i++){
        if(v[i]%2==1){
            odds++;
        }
    }
    if(odds>k){
        return false;
    }
    return true;
}