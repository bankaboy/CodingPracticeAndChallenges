/*
Problem - 

Given an array of integers nums, you start with an initial positive 
value startValue.
In each iteration, you calculate the step by step sum of startValue 
plus elements in nums (from left to right).
Return the minimum positive value of startValue such that the step 
by step sum is never less than 1.

Example 1:
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2

Example 2:
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 

Example 3:
Input: nums = [1,-2,-3]
Output: 5 

Constraints:
1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>
using namespace std;

// My approach - 

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int len = nums.size(), sum = 0, ans, largestNeg = 0, largestPos = 0;
        for (auto it = nums.begin();it!=nums.end();it++) {
            sum+=*it;
            if (*it<largestNeg) {
                largestNeg = *it;
            }
            if (*it>largestPos) {
                largestPos = *it;
            }
        }
        if (sum<1) {
            ans = 1-sum;
        }
        else {
            ans = 2*largestPos - abs(largestNeg);
        }
        return ans;
    }
};

// Discussion
// Find the smallest number we can get min_sum; our start value 
// should be just enough ti cover that (start - min_sum == 1).

int minStartValue(vector<int>& nums) {
    auto sum = 0, min_sum = 0;
    for (auto n : nums) {
        sum += n;
        min_sum = min(min_sum, sum);
    }
    return -min_sum + 1;
}