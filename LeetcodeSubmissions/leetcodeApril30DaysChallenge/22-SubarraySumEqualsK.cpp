/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

/*
Maintain a sum of elements upto each element(prefix sum). Need is the amount needed to reach sum of k.
Increase the count of answer by the number of times that amount is used.
Increase by one each time the prefix sum is reached.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), answer =0, pref=0;
        unordered_map<int,int> countPref;
        countPref[pref]++;
        for(int r=0;r<n;r++) {
            pref+=nums[r];
            int need = pref-k;
            answer += countPref[need];
            countPref[pref]++;
        }
        return answer;
    }
};
