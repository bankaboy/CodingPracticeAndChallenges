/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0,r = num.size() - 1,mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;           
            if (num[mid] > num[r]) l = mid + 1;
            else if (num[mid] < num[r]) r = mid;
            else r--;
        }
        return num[l];
    }
};
