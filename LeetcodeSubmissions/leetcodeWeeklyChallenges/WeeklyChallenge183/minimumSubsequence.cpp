/*
Problem Statement - 

Given the array nums, obtain a subsequence of the array whose sum of 
elements is strictly greater than the sum of the non included elements 
in such subsequence. 
If there are multiple solutions, return the subsequence with minimum 
size and if there still exist multiple solutions, return the 
subsequence with the maximum total sum of all its elements. A 
subsequence of an array can be obtained by erasing some (possibly 
zero) elements from the array. 
Note that the solution with the given constraints is guaranteed to 
be unique. Also return the answer sorted in non-increasing order.

Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.

Input: nums = [6]
Output: [6]

My code - 

vector<int> minSubsequence(vector<int>& nums) {
    vector<int> others;
    int prev_length = 0;
    for (auto it = nums.begin(); it!=nums.end(); it++) {
        for (auto it1 = it; it1!=nums.end(); it1++) {
            others.clear();
            others.push_back(*it1);
            nums.erase(it1);
            if (accumulate(others.begin(),others.end(),0)>accumulate(nums.begin(),nums.end(),0) && others.size()<prev_length)
                return others;
            else 
                prev_length = others.size();
        } 
    }
    return others;
    // accumulate(a.begin(), a.end(), 0);
}
*/

// Intuition: pick the largest number from the array and add it to 
// subsequence. Repeat till the subsequence sum sub_sum is greater 
// than the remaining sum rem_sum. Priority queue is the natural 
// choice to pull next largest numbers.

#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
using namespace std;

vector<int> minSubsequence(vector<int>& nums) {
    vector<int> res;
    auto sub_sum = 0;
    int rem_sum = accumulate(begin(nums), end(nums), 0);
    priority_queue<int> pq(begin(nums), end(nums));
    while (sub_sum <= rem_sum / 2) {
        res.push_back(pq.top());
        sub_sum += res.back();
        pq.pop();
    }
    return res;
}