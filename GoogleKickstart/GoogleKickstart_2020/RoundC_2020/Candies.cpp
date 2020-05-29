/*
Problem
Carl has an array of N candies. The i-th element of the array (indexed starting from 1) is Ai representing sweetness value of the i-th candy. He would like to perform a series of Q operations. There are two types of operation:
Update the sweetness value of a candy in the array.
Query the sweetness score of a subarray.

The sweetness score of a subarray from index l to r is: Al × 1 - Al+1 × 2 + Al+2 × 3 - Al+3 × 4 + Al+4 × 5 ...

More formally, the sweetness score is the sum of (-1)i-lAi × (i - l + 1), for all i from l to r inclusive.

For example, the sweetness score of:
[3, 1, 6] is 3 × 1 - 1 × 2 + 6 × 3 = 19
[40, 30, 20, 10] is 40 × 1 - 30 × 2 + 20 × 3 - 10 × 4 = 0
[2, 100] is 2 × 1 - 100 × 2 = -198

Carl is interested in finding out the total sum of sweetness scores of all queries. If there is no query operation, the sum is considered to be 0. Can you help Carl find the sum?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing N and Q. The second line contains N integers describing the array. The i-th integer is Ai. The j-th of the following Q lines describe the j-th operation. Each line begins with a single character describing the type of operation (U for update, Q for query).
For an update operation, two integers Xj and Vj follow, indicating that the Xj-th element of the array is changed to Vj.
For a query operation, two integers Lj and Rj follow, querying the sweetness score of the subarray from the Lj-th element to the Rj-th element (inclusive).

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total sum of sweetness scores of all the queries.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Ai ≤ 100, for all i.
1 ≤ N ≤ 2 × 105 and 1 ≤ Q ≤ 105 for at most 6 test cases.
For the remaining cases, 1 ≤ N ≤ 300 and 1 ≤ Q ≤ 300.
If the j-th operation is an update operation, 1 ≤ Xj ≤ N and 1 ≤ Vj ≤ 100.
If the j-th operation is a query operation, 1 ≤ Lj ≤ Rj ≤ N.

Test set 1
There will be at most 5 update operations.

Test set 2
There are no special constraints.

Sample

Input -  
2
5 4
1 3 9 8 2
Q 2 4
Q 5 5
U 2 10
Q 1 2
3 3
4 5 5
U 1 2
U 1 7
Q 1 2

Output -
Case #1: -8
Case #2: -3

In sample case #1:
The first query asks for the sweetness score of [3, 9, 8] which is 3 × 1 - 9 × 2 + 8 × 3 = 9.
The second query asks for the sweetness score of [2] which is 2 × 1 = 2.
The third query asks for the sweetness score of [1, 10] which is 1 × 1 - 10 × 2 = -19.
Thus, the final output should be 9 + 2 - 19 = -8.

In sample case #2:
The first and only query asks for the sweetness score of [7, 5] which is 7 × 1 - 5 × 2 = -3.
Thus, the final output should be -3.
*/

// My Solution

#include <bits/stdc++.h>
using namespace std;

void update(vector<int>& A, int pos, int newNum) {
    A[pos] = newNum;
}

int sweetness(vector<int>& A, int begin, int end) {
    int sweetSum = 0, count = 1;
    for (int i=begin;i<=end;i++) {
        if (count%2!=0) {
            sweetSum += (i-begin+1)*A[i];
        } else {
            sweetSum -= (i-begin+1)*A[i];
        }
    }
    return sweetSum;
}

int solver(vector<pair<char,pair<int,int>>> queries, vector<int>& A) {
    int finalSum = 0;
    for (pair<char,pair<int,int>> query: queries) {
        if (query.first == 'U') {
            update(A,query.second.first,query.second.second);
        } else if (query.first == 'Q') {
            finalSum += sweetness(A,query.second.first,query.second.second);
        }
    }
    return finalSum;
}

vector<int> readArray (int length) {
    vector<int> A;
    int elem;
    for (int j=0;j<length;j++) {
        cin>>elem;
        A.push_back(elem);
    }
    return A;
}

vector<pair<char,pair<int,int>>> readQueries (int queryCount) {
    vector<pair<char,pair<int,int>>> queries;
    char queryChar;
    int queryNum1, queryNum2;
    for (int k=0;k<queryCount;k++) {
        cin>>queryChar>>queryNum1>>queryNum2;
        queries.push_back(make_pair(queryChar,make_pair(queryNum1, queryNum2)));
    }
    return queries;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    int n, queryCount, elem, queryChar, queryNum1, queryNum2;
    for (int i=1;i<=T;i++) {
        cin>>n>>queryCount;
        vector<int> A = readArray(n);
        cout<<"Enter Queries "<<queryCount<<"\n";
        vector<pair<char,pair<int,int>>> queries = readQueries(queryCount);
        cout<<"Case #"<<i<<": "<<solver(queries,A)<<"\n";
    }
}

/* Google Analysis

Let us ignore the update operations for now and look at how we can 
answer the queries efficiently. Take the array 
A = [5, 2, 7, 4, 6, 3, 9, 1, 8] as an example. The sweetness score 
for the query (1, 9) from l = 1 to r = 9 is intuitively visualized 
in the following diagram.

The i-th element (-1)i-1Ai × i of the sweetness score sum is 
represented as a stack of i blocks in the i-th column of the 
diagram. The values in every other column are negated to account 
for the sign in the sweetness score sum. Obviously, the sum of all 
squares in the diagram is the sweetness score of the query (1, 9).

A crucial observation is that the sweetness scores for all other 
queries are embedded in the diagram as well. For example, the query 
(5, 8) corresponds to the blue shaded blocks in the diagram below, 
and the sweetness score of (5, 8) can be conveniently computed as 
the sum of all blocks inside the area with the bold outline minus 
the sum of orange and gray blocks. Note, however, that for queries 
(l, r) with even left endpoint l, we should take the additive 
inverse of the value computed this way to obtain the correct 
sweetness score.

Test Set 1
The above observations suggest a solution using prefix sums. Let us 
define the regular prefix sums S(i) as S(0) = 0 and 
S(i) = (-1)i-1Ai + S(i - 1) for i ≥ 1. Similarly, let us define the 
multiple prefix sums MS(i) as MS(0) = 0 and 
MS(i) = (-1)i-1Ai × i + MS(i - 1) for i ≥ 1. Then the sweetness 
score of a query (l, r) is
(-1)l-1(MS(r) - MS(l - 1) - (l - 1) × (S(r) - S(l - 1))).

Computing the prefix sums takes O(N) time, and once we have them, 
each query can be answered in constant time. Therefore, the overall 
time complexity of the algorithm is O(N + Q).

So far we have disregarded the update operations, however, since 
there are no more than 5 of them, we can recompute the prefix sums 
after each update operation without increasing the time complexity.

Test Set 2
Here the number of update operations is unlimited, and the time 
complexity of the previous algorithm becomes O(NQ), which is 
inefficient. However, we can still use very much the same idea by 
maintaining two segment trees – a tree T for storing the values 
(-1)i-1Ai and another tree MT for storing the values (-1)i-1Ai × i. 
Then the answer to a query (l, r) becomes 
(-1)l-1(MT.rangeSum(l, r) - (l - 1) × T.rangeSum(l, r)).

Since updates and range queries in a segment tree take O(log N) 
time, the overall time complexity of the algorithm is O(N + Q log N).
*/