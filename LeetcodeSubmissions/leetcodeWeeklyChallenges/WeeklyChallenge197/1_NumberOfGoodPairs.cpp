/*
Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

// Attempt 1 - Brute force - worked
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if (nums[i]==nums[j]) {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};

// Discussion

class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        return accumulate(A.begin(), A.end(), 0, [count = unordered_map<int, int> {}] (auto a, auto b) mutable {
            return a + count[b]++;
        });
    }
};