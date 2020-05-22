/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

/* Explanation - 
The answer is supposed to be in log(N) time, so searching can be done with binary search.
Since the array is roatated at a certain point , it can be one of the 2 cases - 
    1. If arr[low]<arr[mid], then the rotating point is after the low-mid portion.
    2. If arr[low]>arr[mid], then the rotating point is somewhere in the low-mid portion.
Move the low and high pointers based on the section type
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1, mid;
        while (low<=high) {
            mid = (low+high)/2;
            if (nums[mid]==target)
                return mid;
            if (nums[low]<=nums[mid]) {
                if(nums[low]<=target && target<=nums[mid])
                    high = mid-1;
                else
                    low = mid +1;
            } else {
                if (nums[mid]<target && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};

// Same as above, just recursize instead of iterative
class Solution {
public:
int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size()-1, target);
}
 
int binarySearch(vector<int>& nums, int left, int right, int target){
    if(left>right) 
        return -1;
 
    int mid = left + (right-left)/2;
 
    if(target == nums[mid])
        return mid;
 
    if(nums[left] <= nums[mid]){
        if(nums[left]<=target && target<nums[mid]){
          return binarySearch(nums,left, mid-1, target);
        }else{
          return  binarySearch(nums, mid+1, right, target);
        }
    }else {
        if(nums[mid]<target&& target<=nums[right]){
          return  binarySearch(nums,mid+1, right, target);
        }else{
          return  binarySearch(nums, left, mid-1, target);
        }
    }
}
};
