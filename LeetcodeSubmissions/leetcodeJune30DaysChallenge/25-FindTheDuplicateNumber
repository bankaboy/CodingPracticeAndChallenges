/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least 
one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

// Brute Force - O(n^2) time , constant space
// 1388 ms	11.1 MB
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                if (nums[i]==nums[j]) {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};

// Set - O(n) time , O(n) space
// 64 ms	13 MB
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for (int x:nums) {
            if (s.find(x)!=s.end()) {
                return x;
            } else {
                s.insert(x);
            }
        }
        return 0;
    }
};
