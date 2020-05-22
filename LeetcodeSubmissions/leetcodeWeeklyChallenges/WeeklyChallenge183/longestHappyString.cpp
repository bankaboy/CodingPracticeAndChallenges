/* 
Problem Statement - 

A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which 
satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Input: a = 2, b = 2, c = 1
Output: "aabbc"

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
*/

// Tip: to simplify the logic, preprocess to assume a >= b >= c.
// Intuition: (assuming the preprocessing above) always try to add 
// 'aa'. If, after this, a >= b, add b. Repeat recursivelly for the 
// remaining counts.

#include<iostream>
using namespace std;

string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
    if (a < b)
        return longestDiverseString(b, a, c, bb, aa, cc);
    if (a < c)
        return longestDiverseString(c, b, a, cc, bb, aa);
    if (b < c)
        return longestDiverseString(a, c, b, aa, cc, bb);
    if (b == 0)
        return string(min(2, a), aa);
    auto use_b = a - min(2, a) >= b ? 1 : 0; 
    return string(min(2, a), aa) +  string(use_b, bb) +
        longestDiverseString(a - min(2, a), b - use_b, c, aa, bb, cc);
}