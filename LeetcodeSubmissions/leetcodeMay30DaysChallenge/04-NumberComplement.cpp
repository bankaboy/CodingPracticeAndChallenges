/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary 
representation.

Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to 
output 2.

Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

class Solution {
public:
    int findComplement(int num)  {
        int x = log2(num);  // get number of bits
        int m = 1<<x; // create mask of 1s, will give 1 followed by x-1 0s
        m = m|m-1; // m-1 will be 0 followed by x-1 1s
        num = num^m; // xor with mask
        return num;
    }
};
