/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> first_oc;
        first_oc[0] = 0;
        int answer = 0, pref = 0, n = (int)nums.size();
        for (int i=0;i<n;++i) {
            pref+=(nums[i]==0?-1:1);
            auto it = first_oc.find(pref);
            if (it!=first_oc.end()) {
                answer = max(answer,i+1-first_oc[pref]);
            } else {
                first_oc[pref] = i+1;
            }
        }
        return answer;        
    }
};
