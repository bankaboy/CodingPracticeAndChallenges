#include<bits/stdc++.h>
using namespace std;
/*
Problem 
Given an array nums of 0s and 1s and an integer k, return True if 
all 1's are at least k places away from each other, otherwise 
return False.

Example 1:
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.

Example 2:
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.

Example 3:
Input: nums = [1,1,1,1,1], k = 0
Output: true

Example 4:
Input: nums = [0,1,0,1], k = 1
Output: true

Constraints:
1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] is 0 or 1
*/

/*
My Solution - 
Maintain a list of indexes of 1s. If anywhere the difference
between two indexes is <= k, return false
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> positions;
        for (int i=0;i<n;i++) {
            if (nums[i]==1)
                positions.push_back(i);
        }
        int n1 = positions.size();
        for(int i=1;i<n1;i++)  {
            if (positions[i]-positions[i-1]<=k)
                return false;
        }
        return true;
    }
};

/*
Discussion - 
What I did combined in one loop
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev=-1,pos; // prev stores previous occcuring 1s index and pos stores current 1s index
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                pos=i;
                if((pos-prev)<=k && prev!=-1) // prev=-1 takes care for the first encountered one
                    return false;
                prev=pos;
            }
        }
        return true;
    }
};