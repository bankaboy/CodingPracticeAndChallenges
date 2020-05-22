/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one 
element which appears exactly once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.
*/


// Solution 1 - O(n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> cmap; // map to store element and count
        for (int x:nums) {
            if (cmap.find(x)==cmap.end()) { // x not found in map
                cmap[x] = 1; // add x to map
            } else {
                cmap[x] += 1; // add 1 to count if already there
            }
        }
        for (int x:nums) {
            if (cmap[x]==1) {
                return x;
            }
        }
        return 1;
    }
};

// Solution 2 - O(lgn)
/*
For every element 
if it occurs twice , then its first occurence will be at an even index.
if the first occurence of a number is at odd index and the nextt number is same, means the previous number is the ans.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
	    while(left < right){
    		int mid = (left + right)/2;
    		if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
    			left = mid + 1;
    		else
    			right = mid;
    	}
    	return nums[left];
    }
};
