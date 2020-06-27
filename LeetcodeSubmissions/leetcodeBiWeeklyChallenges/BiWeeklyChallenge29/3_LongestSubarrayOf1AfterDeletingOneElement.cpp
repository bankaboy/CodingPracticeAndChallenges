/*
Given a binary array nums, you should delete one element 
from it.
Return the size of the longest non-empty subarray 
containing only 1's in the resulting array.
Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Example 4:
Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4

Example 5:
Input: nums = [0,0,0]
Output: 0

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/

#include<bits/stdc++.h>
using namespace std;

// My Solution 1 
// https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/
// Modified for current question
// Worked for all except example 2
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt0 = 0, l = 0, max_len = 0, n = nums.size();
        
        for(int i=0;i<n;i++) {
            if (nums[i]==0) 
                cnt0++;
            
            while(cnt0>1) {
                if(nums[l]==0)
                    cnt0--;
                l++;
            }
            max_len = max(max_len-1, i-l);
        }
        return max_len;
    }
};

// My Solution 2
// https://www.geeksforgeeks.org/longest-prime-subarray-after-removing-one-element/
// Accepted
// Article is longest subarray of prime numbers after
// removing a number. Considered 1 as prime and 0 as not.
class Solution {
public:
    vector<bool> prime {false, true};
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        int primecount = 0, res = 0;
        
        for(int i=0;i<n;i++) {
            left[i] = primecount;
            if(prime[nums[i]]) {
                primecount++;
            } else {
                primecount = 0;
            }
        }
        
        primecount = 0; 
        for (int i = n - 1; i >= 0; i--) { 
            right[i] = primecount; 
            if (prime[nums[i]]) { 
                primecount++; 
            } else {
                primecount = 0;
            }
        }
        
        for (int i = 0; i < n; i++)  
            res = max(res, left[i] + right[i]); 
          
        return res;
    }
};

// Discussion
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_sz = 0;
        for (int i = 0, j = 0, skip = 0; i < nums.size(); ++i) {
            skip += nums[i] == 0;
            if (skip > 1)
                skip -= nums[j++] == 0;
            max_sz = max(max_sz, i - j + 1);
        }
        return max_sz - 1;
    }
};