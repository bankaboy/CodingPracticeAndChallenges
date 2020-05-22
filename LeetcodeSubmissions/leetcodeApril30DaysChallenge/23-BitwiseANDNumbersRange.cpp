/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

// Copied, as I couldn't come up with anything better than brute force which exceeded time limits
// http://yucoding.blogspot.com/2015/06/leetcode-question-bitwise-and-of.html

/*
Iterative - 
The last bit of the resultant will not be 1 unless they are the same number. This is because for each m, the last bit 
of m+1 will be opposite(last bit flips each number) and result in 0 after bitwise and.
Therefore the last bit will be 0 till if n>m because each time the number is being AND(ed) with its next. 
We can move to next bit by right shifting. If m and n match, we stop, since they will result in the same number again.
k is the number of left shifts we need to get back to answer, since we right shift m and n at the end of each iteration
when n>m.
We then get back the zeroes lost at the end by right shifts by left shifting k(counter for left shifts) times.
Since for all the right shift cases, the last result bit was 0, there is no loss of result using k left shifts.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k = 0;
        while(1) {
            if (n>m) {
                k = k+1;
            } else {
                return m<<k;
            }
            m = m>>1;
            n = n>>1;
        }
        return m;
    }
};

/* 
Recursive - 
The variable k is replaced by leftShifting the number by 1 for each call. The logic is same.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       if (n>m){
           return rangeBitwiseAnd(m>>1, n>>1)<<1;
       }else{
           return m;
       }
    }
};
