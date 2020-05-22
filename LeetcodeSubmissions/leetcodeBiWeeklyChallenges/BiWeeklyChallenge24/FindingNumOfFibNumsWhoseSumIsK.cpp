/* Problem - 

Given the number k, return the minimum number of Fibonacci numbers 
whose sum is equal to k, whether a Fibonacci number could be used 
multiple times.
The Fibonacci numbers are defined as:
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 , for n > 2.
It is guaranteed that for the given constraints we can always find 
such fibonacci numbers that sum k.

Example 1:
Input: k = 7
Output: 2 
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.

Example 2:
Input: k = 10
Output: 2 
Explanation: For k = 10 we can use 2 + 8 = 10.

Example 3:
Input: k = 19
Output: 3 
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 
Constraints:
1 <= k <= 10^9
*/

#include<iostream>
#include<vector>
using namespace std;

// My Solution -
// Find closest smaller element to k and keep subtracting and adding
// 1 to the answer

class Solution {
public:
    int returnClosest(int seq[], int n, int target) {
        int ans = 0, low = 0, high = n, mid;
        while(low<high) {
            mid = (low+high)/2;
            if (seq[mid]<target && seq[mid+1]>target ) {
                ans = seq[mid];
            }
            else if (seq[mid]>target && seq[mid-1]<target) {
                ans = seq[mid-1];
            }
            else if (seq[mid]<target) {
                low = mid-1;
            }
            else if (seq[mid]>target) {
                high = mid+1;
            }
            else {
                ans = seq[mid];
            }
        }
        return ans;
    } 
    
    int findMinFibonacciNumbers(int k) {
        int fib[k+4];
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        for(int i=3;i<k+4;i++) {
            fib[i] = fib[i-1]+fib[i-2];
        }
        int answer = 0, temp = k;
        while (temp>0) {
            temp = temp - returnClosest(fib,k+4,temp);
            answer++;
        }
        return answer;
    }
};

// Discussion - greedy


int findMinFibonacciNumbers(int k) {
    int f1 = 0, f2 = 1;
    while (f2 <= k) {
        swap(f1, f2);
        f2 += f1;
    }
    return 1 + (k == f1 ? 0 : findMinFibonacciNumbers(k - f1));
}