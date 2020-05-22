/*Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

// Solution -  Save product of elements on left upto ith element. 
// Similarly store the product of elements on right after ith element.
// Multiply corresponding elements of left and right for each element.
/*
Example : 
nums =    [1 ,2 ,3,4]
left =    [1 ,1 ,2,6]
right =   [24,12,4,1]
res =     [24,12,8,6]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left[n], right[n];
        left[0] = 1; // store product  of elements in the left subarray
        for(int i=1;i<n;i++)
            left[i] = nums[i-1]*left[i-1];
        
        right[n-1] = 1; // store product  of elements in the right subarray
        for(int j=n-2;j>=0;j--)
            right[j] = nums[j+1]*right[j+1];
        
        for (int i=0;i<n;i++)
            nums[i] = left[i]*right[i];
        
        return nums;        
    }
};

