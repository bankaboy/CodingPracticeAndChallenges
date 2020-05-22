/* Constrained Subset sum
Given an integer array nums and an integer k, return the maximum 
sum of a non-empty subset of that array such that for every two 
consecutive integers in the subset, nums[i] and nums[j], 
where i < j, the condition j - i <= k is satisfied.
A subset of an array is obtained by deleting some number of 
elements (can be zero) from the array, leaving the remaining 
elements in their original order.

Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subset is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subset must be non-empty, so we choose the largest number.

Example 3:
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subset is [10, -2, -5, 20].

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#include<vector>
#include<string>
using namespace std;

// Discussion

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp {nums[0]};
        deque<int> decrease {nums[0]};
        int res = nums[0];
        
        for (int i=1; i<nums.size(); i++) {
            if (i > k && decrease[0] == dp[i - k - 1])
                decrease.pop_front();
            int tmp = max(nums[i], decrease[0] + nums[i]);
            dp.push_back(tmp);
            while (!decrease.empty() && decrease.back() < tmp)
                decrease.pop_back();
            decrease.push_back(tmp);
            
            res = max(res, tmp);
        }
        return res;
        
    }
};

/*
Idea
This is a typical knapsack problem. we maintain an array dp, where 
dp[i] is the maximum sum we can get from nums[:i] and nums[i] is 
guaranteed to be included.

Base case: dp[0] = nums[0]
state transition: 
dp[i] = max(dp[i - k], dp[i-k+1], ..., dp[i - 1], 0) + x
NOTE that x can be a fresh start when all the previous dp are 
negative.
This algorithm is only O(n * k), we need to improve it to O(n) 
because both k and n can be 10^5.

The Idea is straight-forward, we can maintain an non-increasing 
deque decrease that records the maximum value among dp[i - k],
dp[i-k+1], ..., dp[i - 1]. When encountering a new value x, we 
only record it in decrease if x > decrease[decrease.size - 1]. 
Thus the first element in decrease will always be the largest 
value we want.

Complexity
Time: O(n)
Space: O(n)

*/