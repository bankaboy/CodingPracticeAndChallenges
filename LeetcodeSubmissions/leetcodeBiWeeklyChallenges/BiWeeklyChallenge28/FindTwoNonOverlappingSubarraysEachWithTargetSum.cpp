#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr and an integer target.

You have to find two non-overlapping sub-arrays of arr each with 
sum equal target. There can be multiple answers so you have to find 
an answer where the sum of the lengths of the two sub-arrays is 
minimum.

Return the minimum sum of the lengths of the two required sub-arrays, 
or return -1 if you cannot find such two sub-arrays.

Example 1:
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The 
sum of their lengths is 2.

Example 2:
Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of 
sum = 7 ([7], [3,4] and [7]), but we will choose the first and 
third sub-arrays as the sum of their lengths is 2.

Example 3:
Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.

Example 4:
Input: arr = [5,5,4,4,5], target = 3
Output: -1
Explanation: We cannot find a sub-array of sum = 3.

Example 5:
Input: arr = [3,1,1,1,5,1,2,1], target = 3
Output: 3
Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an 
answer because they overlap.

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 1000
1 <= target <= 10^8
*/

/* 
My Solution 1 - 
For all partitions, pick one subarray from the left and one from the
right.
Problem -  not minimum subarray
*/
class Solution {
public:
    // find length of subarray with sum equal to target in given range
    int subArraySumLength(vector<int> v, int start, int end, int target) {
        int curr_sum = v[0], i;
        for(i=1; i<end; i++) {
            while (curr_sum>target && start<i-1) {
                curr_sum = curr_sum - v[start];
                start++;
            }
            if (curr_sum == target) {
                return start-(i-1)+1;
            }
            if (i<end) {
                curr_sum = curr_sum+v[i];
            }
        }
        return -1;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), len = INT_MAX;
        bool flag = true; // denotes that there was no possibility to find subarray
        for (int j=0;j<n;j++) {
            int len1 = subArraySumLength(arr,0,j, target);
            int len2 = subArraySumLength(arr,j+1,n, target);
            if (len1==-1 || len2==-1) {
                flag = true;
                continue;
            } else {
                flag = false;
                len = min(len, len1+len2);
            }
        }
        if (flag) {
            // if no possibility was found till the end
            return -1;
        } 
        return len;
    }
};

/*
My Solution 2 
Find min subarray with target on both sides of partition
*/
class Solution {
public:
    int subArraySumLength(vector<int> v, int start, int end, int target) {
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = start; i < end; i++) {
            sum += v[i];
            while (sum >= target) {
                ans = min(ans, i + 1 - left);
                sum -= v[left++];
            }
        }
    return (ans != INT_MAX) ? ans : -1;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), len = INT_MAX;
        bool flag = true; // denotes that there was no possibility to find subarray
        for (int j=0;j<n;j++) {
            int len1 = subArraySumLength(arr,0,j, target);
            int len2 = subArraySumLength(arr,j+1,n, target);
            if (len1==-1 || len2==-1) {
                flag = true;
                continue;
            } else {
                flag = false;
                len = min(len, len1+len2);
            }
        }
        if (flag) {
            // if no possibility was found till the end
            return -1;
        } 
        return len;
    }
};

// Attempt 3 
class Solution {
public:
    int subArraySumLength(vector<int> v, int start, int end, int target) {
        int ans = INT_MAX, left = -1, right = -1;
        int sum = 0;
        for (int i=start; i<end; i++) {
            int currentSum = 0;
            for(int j=i; j<end && (j-1+1)<ans; j++) {
                currentSum += v[j];
                if (currentSum==target) {
                    left = i;
                    right = j;
                    ans = right-left+1;
                    break;
                }
            }
        }
        return ans;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), len = INT_MAX;
        bool flag = true; // denotes that there was no possibility to find subarray
        for (int j=0;j<n;j++) {
            int len1 = subArraySumLength(arr,0,j, target);
            int len2 = subArraySumLength(arr,j+1,n, target);
            if (len1==-1 || len2==-1) {
                flag = true;
                continue;
            } else {
                flag = false;
                len = min(len, len1+len2);
            }
        }
        if (flag) {
            // if no possibility was found till the end
            return -1;
        } 
        return len;
    }
};

// Discussion - 
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        map<int, int> _map; // can use unordered_map as well
        vector<pair<int, pair<int, int> > > subs;
        
        _map[0] = -1;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(sum - target >= 0 && _map.find(sum - target) != _map.end()) {
                subs.push_back({i - _map[sum-target], {_map[sum - target] + 1, i}});
            }
            _map[sum] = i;
        }
        
        sort(subs.begin(), subs.end());
        if(subs.size() < 2)
            return -1;
        
        
        for(int i = 0; i < subs.size() - 1; i++) {
            
            for(int j = i + 1; j < subs.size(); j++) {
                if(subs[i].second.second < subs[j].second.first || subs[i].second.first > subs[j].second.second)
                    return subs[i].first + subs[j].first; 
            }
        }
        return -1;
    }
};