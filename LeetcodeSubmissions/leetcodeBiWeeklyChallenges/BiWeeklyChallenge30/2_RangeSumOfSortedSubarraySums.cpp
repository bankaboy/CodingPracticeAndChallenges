/*
Given the array nums consisting of n positive integers. You computed 
the sum of all non-empty continous subarrays from the array and 
then sort them in non-decreasing order, creating a new array of 
n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right 
(indexed from 1), inclusive, in the new array. Since the answer can 
be a huge number return it modulo 10^9 + 7.

Example 1:
Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. 
After sorting them in non-decreasing order we have the new array 
[1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index 
le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 

Example 2:
Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the 
new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers 
from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:
Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50

Constraints:
1 <= nums.length <= 10^3
nums.length == n
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2
*/

#include<bits/stdc++.h>
using namespace std;

// Attempt 1 - Brute force (TLE)
class Solution {
public:
    void dispVector(vector<int> nums) {
        int n = nums.size();
        for (int i=0;i<n;i++) {
            cout<<nums[i]<<" ";
        }
    }
    int subsum(vector<int> arr,int i,int j) {
        int sum = 0;
        for (int k=i;k<=j;k++) {
            sum+=arr[k];
        }
        return sum;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subsums;
        for (int i=0;i<n;i++) {
            subsums.push_back(nums[i]);
            for (int j=i+1;j<n;j++) {
                subsums.push_back(subsum(nums,i,j));
            }
        }
        sort(subsums.begin(), subsums.end());
        long long int sum = 0;
        for(int i=left-1;i<=right-1;i++) {
            sum+=subsums[i];
        }
        return sum%1000000007;
    }
};

// Discussion - 
class Solution {
public:
#define maxv 100
#define MOD 1000000007

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=(solve(nums,right)-solve(nums,left-1))%MOD;
        if(ans<0)  ans+=MOD;
        return ans;
    }
    
    int solve(vector<int>& v, int position){
     // find the sum of subarrays for that sum is at <=position in the sorted array
        if(position<1)return 0;
        
        int sum=bsearch(v, position);
        int ans=0;
        int s=0;
        int n=v.size();
        
        int count=0;
        
        vector<int> mult_sums(n),prefix_sums(n);
        prefix_sums[0]=v[0];
        mult_sums[0]=v[0];
        for(int i=1;i<n;i++){
            prefix_sums[i]=(prefix_sums[i-1]+v[i])%MOD;
            mult_sums[i]=(mult_sums[i-1]+(i+1)*v[i])%MOD;
        }
            
        for(int start=0,end=0;end<n;end++){
            s+=v[end];
            for(;start<=end&&s>sum;start++)
                s-=v[start];
            
            count+=end-start+1;
            
            if(start<=end){
                ans+=mult_sums[end]-(start==0?0:mult_sums[start-1]);
                if(start>0) ans-=((long) start*(prefix_sums[end]-prefix_sums[start-1]))%MOD;
                ans%=MOD;
            }
        }
        ans-=((long) (count-position)*sum)%MOD;
        ans%=MOD;
        if(ans<0) ans+=MOD;
        
        return ans;
    }
    
    int bsearch(vector<int>& v, int position){
    // return the position-th number in the sorted sequence
        int n=v.size();
        int low=0;
        int high=maxv*n;
        
        while(low<high){
            int mid=(low+high)/2;

            if(count_subarary_with_target(v,mid)<position) low=mid+1;
            else high=mid;
        }
        return low;
    }
    
    int count_subarary_with_target(vector<int>& v, int target){
        
        int n=v.size();
        int s=0;
        int count=0;
        for(int start=0,end=0;end<n;end++){
           s+=v[end];
           for(;start<=end&&s>target;start++)
               s-=v[start];
                
           count+=end-start+1;
        }
        return count;
    }

};