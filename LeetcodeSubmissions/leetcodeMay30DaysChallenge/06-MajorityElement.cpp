/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int x:nums) {
            if (mp.find(x)!=mp.end()) {
                mp[x]+=1;
            } else {
                mp[x] = 1;
            }
        }
        for(int x:nums) {
            if (mp[x]>n/2) {
                return x;
            }
        }
        return -1;
    }
};
