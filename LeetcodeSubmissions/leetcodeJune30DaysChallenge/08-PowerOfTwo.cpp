/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/

/*
n should not be 0 and ceiling and floor of log2 should be same. (meaning there is no fractional part)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n!=0 && (ceil(log2(n)) == floor(log2(n)));
    }
};
