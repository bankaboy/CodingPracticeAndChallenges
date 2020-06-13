/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this 
subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if(n==0) return ans;
        sort(nums.begin(), nums.end()); 
        vector <int> divCount(n, 1); 
        vector <int> prev(n, -1); 
        int max_ind = 0; 
        
        for (int i=1; i<n; i++)  { 
            for (int j=0; j<i; j++) { 
                if (nums[i]%nums[j] == 0) { 
                    if (divCount[i] < divCount[j] + 1) { 
                        divCount[i] = divCount[j]+1; 
                        prev[i] = j; 
                    } 
                } 
            } 
            if (divCount[max_ind] < divCount[i]) 
                max_ind = i; 
        } 
        
        int k = max_ind; 
        while (k >= 0) { 
            ans.push_back(nums[k]); 
            k = prev[k]; 
        } 
        return ans;
    }
};
