/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique 
triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

// Brute force , multiple copies of same answers - TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                for (int k=j+1;k<n;k++) {
                    vector<int> v;
                    if (nums[i]+nums[j]+nums[k]==0) {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        ans.push_back(v);
                    }
                }
            }
        }
        return ans;
    }
};

// Brute force + set - TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans_set;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                for (int k=j+1;k<n;k++) {
                    vector<int> v;
                    if (nums[i]+nums[j]+nums[k]==0) {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        sort(v.begin(), v.end());
                        ans_set.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans(ans_set.begin(), ans_set.end());
        return ans;
    }
};

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        
        vector<vector<int>> res;    
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {

                int sum = num[front] + num[back];
            
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
    
                else if (sum > target)
                    back--;
    
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;
    
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;
        }   
        return res;
    }
};
