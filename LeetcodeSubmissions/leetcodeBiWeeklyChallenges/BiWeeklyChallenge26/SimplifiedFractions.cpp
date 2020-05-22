#include<bits/stdc++.h>
using namespace std;

/*
Given an integer n, return a list of all simplified fractions 
between 0 and 1 (exclusive) such that the denominator is 
less-than-or-equal-to n. The fractions can be in any order.

Example 1:
Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.

Example 2:
Input: n = 3
Output: ["1/2","1/3","2/3"]

Example 3:
Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".

Example 4:
Input: n = 1
Output: []

Constraints:
1 <= n <= 100
*/

/* My solution - 
For num go from 1 to n-1:
    For den go from num+1 to n:
        if the num>1 and gcd(num,den)>1:
            means the fraction can be simplified and has most 
            probably been added to the list already. Skip
        Otherwise add the fraction
*/

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int num=1;num<=n-1;num++) {
            for (int den=num+1;den<=n;den++) {
                if (__gcd(num,den)==1) { continue; }
                string fraction = to_string(num)+"/"+to_string(den);
                ans.push_back(fraction);
            }
        }
        return ans;
    }
};