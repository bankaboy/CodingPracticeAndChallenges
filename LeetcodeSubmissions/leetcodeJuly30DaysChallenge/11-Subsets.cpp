/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    void generate(int index , vector<int>& curr , vector<int>& nums , vector<vector<int>>& Result)  {
        int prev = -1;
        Result.push_back(curr);
        for(int i=index ; i<nums.size() ; i++) {
            if(prev == nums[i] && i>index)
                continue;
            curr.push_back(nums[i]);
            generate(i+1 , curr , nums , Result);
            prev = curr[curr.size() - 1];
            curr.erase(curr.end()-1);  // takes in iterator
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>Result;
        if(nums.size()==0)
            return {};
        vector<int>curr;
        sort(nums.begin(),nums.end());
        generate(0,curr,nums,Result);
        return Result;
    }
};
