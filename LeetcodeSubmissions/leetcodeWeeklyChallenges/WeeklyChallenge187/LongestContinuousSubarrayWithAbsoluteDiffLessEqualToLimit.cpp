#include<bits/stdc++.h>
using namespace std;

/* 
Problem - 
Given an array of integers nums and an integer limit, return the 
size of the longest continuous subarray such that the absolute 
difference between any two elements is less than or equal to limit.
In case there is no subarray satisfying the given condition return 0.

Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
*/

/* My Solution - 
For each element create a continuous subarray until the difference
of the new element with the max or min of exisitng array is greater
than limit
Working - OK, Time limit Exceeded
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        vector<int> ans;
        int maxLength=0, n = nums.size();
        for(int i=0;i<n;i++) {
            int maxNum = nums[i], minNum = nums[i];
            for (int j=i;j<n;j++) {
                maxNum = max(maxNum,nums[j]);
                minNum = min(minNum,nums[j]);
                if (abs(maxNum-nums[j])<=limit && abs(minNum-nums[j])<=limit) 
                    ans.push_back(nums[j]);
                else 
                    break;
            }
            int length = ans.size();
            maxLength = max(length, maxLength);
            ans.clear();
        }
        return maxLength;        
    }
};

// Discussion - 
class Solution {
public:
    int longestSubarray(vector<int>& n, int l) {
        int j=0,ans=0;
        while(1){
            int z=0,MAX=0,MIN=INT_MAX,i=j;  
        for(;i<n.size();i++){
            MAX=max(MAX,n[i]); MIN=min(MIN,n[i]);
            if(MAX-MIN>l)break;       //we just need max and min difference of the subarray
            z++;
        }
                 ans=max(ans,z);
            if(i==n.size())break;       //if we reached the end stop
                 j++;                  //increase the index
        }
        return ans;
    }
};


// My modified Solution - 
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLength=0, n = nums.size();
        for(int i=0;i<n;i++) {
            int length = 0;
            int maxNum = nums[i], minNum = nums[i];
            int j=i;
            for (;j<n;j++) {
                maxNum = max(maxNum,nums[j]);
                minNum = min(minNum,nums[j]);
                if (maxNum-minNum>limit) 
                    break;
                length++;
            }
            maxLength = max(length, maxLength);
            if (j==n) 
                break;
        }
        return maxLength;        
    }
};