/*
Problem
Cristobal has an array of N (possibly negative) integers. The i-th integer in his array is Ai. A contiguous non-empty subarray of Cristobal's array is perfect if its total sum is a perfect square. A perfect square is a number that is the product of a non-negative integer with itself. For example, the first five perfect squares are 0, 1, 4, 9 and 16.

How many subarrays are perfect? Two subarrays are different if they start or end at different indices in the array, even if the subarrays contain the same values in the same order.

Input
The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case contains the integer N. The second line contains N integers describing Cristobal's array. The i-th integer is Ai.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of perfect subarrays.

Limits
Memory limit: 1GB.
1 ≤ T ≤ 100.
-100 ≤ Ai ≤ 100, for all i.

Test set 1
Time limit: 20 seconds.
1 ≤ N ≤ 1000.

Test set 2
Time limit: 30 seconds.
For up to 5 cases, 1 ≤ N ≤ 105.
For the remaining cases, 1 ≤ N ≤ 1000.

Sample

Input
 	
Output
 
3
3
2 2 6
5
30 30 9 1 30
4
4 0 0 16

  
Case #1: 1
Case #2: 3
Case #3: 9

  
In sample case #1, there is one perfect subarray: [2 2] whose sum is 22.

In sample case #2, there are three perfect subarrays:
[9], whose total sum is 32.
[1], whose total sum is 12.
[30 30 9 1 30], whose total sum is 102.

In sample case #3, there are nine perfect subarrays:
[4], whose total sum is 22.
[4 0], whose total sum is 22.
[4 0 0], whose total sum is 22.
[0], whose total sum is 02.
[0 0], whose total sum is 02.
[0 0 16], whose total sum is 42.
[0], whose total sum is 02.
[0 16], whose total sum is 42.
[16], whose total sum is 42.

Note: We do not recommend using interpreted/slower languages for the test set 2 of this problem
*/

#include <bits/stdc++.h>
using namespace std;

// Attempt 1 - Brute force
// correct answer in test case but time limit exceeded
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0);
}

int solver(int len, vector<long double> A)  {
    long double s = 0;
    int count = 0;
    for(int i=0;i<len;i++) {
        s+=A[i];
        if(isPerfectSquare(s)) { count++; } 
        for(int j=i+1;j<len;j++){
            s+=A[j];
            if(isPerfectSquare(s)) { count++; }
        }
        s=0;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    int len;
    long double elem;
    for (int i=1;i<=T;i++) {
        cin>>len;
        vector<long double> A;
        for (int j=0;j<len;j++) {
            cin>>elem;
            A.push_back(elem);
        }
        cout<<"Case #"<<i<<": "<<solver(len,A)<<"\n";
    }
}

/*
Google analysis - 

Analysis
For test set 1, we can use the brute force approach to generate all 
subarray sums, check if each one is a square and return the total 
count. This would be enough to pass all the test cases under the 
time complexity.

For test set 2, looking at the problem constraints, we can 
estabilish that the largest subarray sum possible across all 
testcases would be N*MAX_A where MAX_A is the largest element in A. 
Therefore, we can precompute all squares ≤ N*MAX_A. This amounts to 
√(N*MAX_A) squares. Let's call this S[].

First, let's define Res[] where Resi stores the number of subarrays 
ending at index i with subarray sum that is a perfect square.
Note: sum(A[L....R]) = sum(A[0.....R]) - sum(A[0....L-1]) 
for 0 < L ≤ R ≤ N..
Next, define an array P[] that keeps count of the number of indices 
i such that A[0...i] amount to a specific prefix_sum. i.e., 
P[prefix_sum] should give us the number of indices i such that 
sum(A[0...i])=prefix_sum. However, we could have negative 
prefix_sum values and hence P[prefix_sum] could be an invalid 
lookup. To resolve this, instead of mapping a prefix_sum to 
P[prefix_sum], we map it to P[prefix_sum + offset], where 
offset = min(sum(A[0.....i]), 0)*-1 for 0 ≤ i < N. i.e., 
The minimum among the N+1 (+1 for the empty prefix) prefix_sum 
values possible which can be computed with a single pass over A. 
Note that the offset is at least 0.

Next, we iterate the A left to right, while maintaining the sum of 
elements seen so far - let's call that prefix_sum. Now, at every 
i-th index, we ask the question, How many subarrays end at i and 
have the subarray sum which is also a square?
To answer this, we iterate S[] and for each square Sk, we add 
P[(prefix_sum-Sk) + offset] to Res[i]. Why so? - P is built as we 
iterate A and hence, at a certain index i, P holds the mapping of 
{prefix_sum, count} where count is the number of indices j (< i) 
such that sum(A[0....j])=prefix_sum. Therefore, 
P[(prefix_sum-Sk) + offset] holds the number of indices such that 
sum(A[j...i])=Sk.
We also increment the count of P[prefix_sum+offset] by 1 to record 
that sum(A[0....i])=prefix_sum. Finally, summing up all values Res[] 
would give us our answer.

Since we traverse A once, iterate S[] for every index i and lookup 
in P[] is O(1), the total time complexity for this solution is 
O(N*√(N*MAX_A)).

Appendix
A subtle observation and a potential improvement is to early exit 
on iteration of S[] at every stage. As mentioned earlier, we check 
P[(prefix_sum-Sk) + offset] and notice that at some point 
(prefix_sum-Sk) + offset could become < 0 which indicates not only 
that accessing P would be invalid, but also that Sk is too large 
to be obtained from all elements upto the current index i. We can 
use this criteria as a way to early exit the iteration on S[]. 
The asymptotic time complexity would remain the same, but would be 
slightly faster in run-time.

Next, instead of using an array with an offset for lookup of prefix 
sums , we could use a normal map, which would remove the need of an 
offset, but adds the cost of lookup that would take logarithmic 
time instead of the O(1). This solution may also be accepted if 
written efficiently and the time comoplexity would be 
O(N*log(N)*√(N*MAX_A)).
*/