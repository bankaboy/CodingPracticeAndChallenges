/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false
*/

// Using newton's method

class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x*x>num) {
            x = (x+num/x)>>1;
        }
        return x*x == num;
    }
};
