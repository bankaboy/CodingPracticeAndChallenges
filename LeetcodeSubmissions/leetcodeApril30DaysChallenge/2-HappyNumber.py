'''
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
'''

class Solution:
    def sum_of_squares(self, n:int) -> int:
        sum = 0
        while(n>0):
            sum += (n%10)*(n%10)
            n = n//10;
        return sum
    def isHappy(self, n: int) -> bool:
        prev_sols = []
        while True:
            n = self.sum_of_squares(n);
            if n==1:
                return True
            if n in prev_sols:
                return False
            else:
                prev_sols.append(n)
