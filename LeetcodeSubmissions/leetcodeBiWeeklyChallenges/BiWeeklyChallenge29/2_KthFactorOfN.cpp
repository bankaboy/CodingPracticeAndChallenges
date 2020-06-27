/*
2_Medium

Given two positive integers n and k.
A factor of an integer n is defined as an integer i where 
n % i == 0.
Consider a list of all factors of n sorted in ascending 
order, return the kth factor in this list or return -1 if 
n has less than k factors. 

Example 1:
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

Example 2:
Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.

Example 3:
Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.

Example 4:
Input: n = 1, k = 1
Output: 1
Explanation: Factors list is [1], the 1st factor is 1.

Example 5:
Input: n = 1000, k = 3
Output: 4
Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000].
 
Constraints:
1 <= k <= n <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

// Brute force - Accepted(How??)
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> facs;
        for(int i=1;i<=n;i++) {
            if (n%i==0) {
                facs.push_back(i);
            }
        }
        if (facs.size()<k) {
            return -1;
        }
        sort(facs.begin(), facs.end());
        return facs[k-1];
    }
};

// Discussion - used set instead of vector
class Solution {
public:
    int kthFactor(int n, int k) {
        int res = 0;
        set<int> s;
        for(int i = 1; i <= sqrt(n); ++i)
        {
            if (n % i == 0) 
            { 
                s.insert(i); 
                if (i != sqrt(n)) 
                    s.insert(n / i); 
            }
        }
        if(s.size() < k)
            return -1;
        auto it = s.begin();
        while(--k > 0)
            it++;
        return *it;
    }
};