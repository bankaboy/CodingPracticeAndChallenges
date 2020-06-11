/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are 
adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's 
and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

// Solution 1 - Counting Sort -  extra counting space
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counter(3);
        // count occurences of each element
        for (int x: nums) {
            counter[x]++;
        }
        int n = nums.size(); 
        for (int i=0;i<n;i++) {
            if (i<counter[0]) { nums[i] = 0; }
            else if (i<counter[0]+counter[1]) { nums[i] = 1; }
            else { nums[i] = 2; }
        }
    }
};

// Solution 2 - One pass swaps - constant space
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                // swap the zeroes to the start
                // first 0 sorted and ++ low
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1) {
                // go to next element, keep 1 in the middle
                mid++;
            }
            else if(nums[mid] == 2) {
                // swap the 2 to the end
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
