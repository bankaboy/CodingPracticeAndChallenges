/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

// 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) {
            return true;
        }
        int jumps = 0;
        pair<int,int> interval{0,0};
        while(true) {
            jumps ++;
            int can_reach = -1;
            for (int i=interval.first;i<=interval.second;i++) {
                can_reach = max(can_reach, i+nums[i]);
            }
            if (can_reach>=n-1) {
                cout<<"Lowest number of jumps "<<jumps<<"\n";
                return true;
            }
            interval = {interval.second+1,can_reach};
            if (interval.first>interval.second) {
                return false;
            }
        }
        return false;
    }
};

// 2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int can_reach = 0;
        for(int i=0;i<=can_reach;++i) {
            if (i==n-1) {
                return true;
            }
            can_reach = max(can_reach,i+nums[i]);
        }
        return false;
    }
};
