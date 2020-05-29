/*
Problem

Bucket is planning to make a very long journey across the 
countryside by bus. Her journey consists of N bus routes, numbered 
from 1 to N in the order she must take them. The buses themselves 
are very fast, but do not run often. The i-th bus route only runs 
every Xi days.
More specifically, she can only take the i-th bus on day Xi, 2Xi, 
3Xi and so on. Since the buses are very fast, she can take multiple 
buses on the same day.
Bucket must finish her journey by day D, but she would like to start 
the journey as late as possible. What is the latest day she could 
take the first bus, and still finish her journey by day D?
It is guaranteed that it is possible for Bucket to finish her 
journey by day D.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the two integers N and D. Then, another line follows containing N integers, the i-th one is Xi.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the latest day she could take the first bus, and still finish her journey by day D.

Limits
Time limit: 10 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Xi ≤ D.
1 ≤ N ≤ 1000.
It is guaranteed that it is possible for Bucket to finish her journey by day D.

Test set 1
1 ≤ D ≤ 100.

Test set 2
1 ≤ D ≤ 1012.

Sample

Input
3
3 10
3 7 2
4 100
11 10 5 50
1 1
1

Output
Case #1: 6
Case #2: 99
Case #3: 1

  
In Sample Case #1, there are N = 3 bus routes and Bucket must arrive by day D = 10. She could:
Take the 1st bus on day 6 (X1 = 3),
Take the 2nd bus on day 7 (X2 = 7) and
Take the 3rd bus on day 8 (X3 = 2).

In Sample Case #2, there are N = 4 bus routes and Bucket must arrive by day D = 100. She could:
Take the 1st bus on day 99 (X1 = 11),
Take the 2nd bus on day 100 (X2 = 10),
Take the 3rd bus on day 100 (X3 = 5) and
Take the 4th bus on day 100 (X4 = 50),

In Sample Case #3, there is N = 1 bus route and Bucket must arrive by day D = 1. She could:
Take the 1st bus on day 1 (X1 = 1).

*/
#include<iostream>
#include<vector>
using namespace std;

int testCase(vector<int>& B, int n, int d) {
    while (n>0)
    {
        for (auto it=B.begin();it!=B.end();it++) {
            if (n==0)
                break;
            if (d%*it==0) {
                n--;
                d--;
            }
        }
    }
    return d;
}

int main() {
    int t;
    cin>>t;
    vector<pair<int,int>> ans;
    
    for (int i=0;i<t;i++) {
        int n, d, b; 
        // n - number of bus routes
        // d - latest day to arrive
        // b - value of each bus
        vector<int> B; // vector of buses
        cin>>n>>d;
        for (int j=0;j<n;j++) {
            cin>>b;
            B.push_back(b);
        }
        ans.push_back({i+1,testCase(B,n,d)});
    }
    for (int i=0;i<t;i++) {
        cout<<"Case #"<<ans[i].first<<": "<<ans[i].second<<endl;
    }
}

/*
Analysis
We need to take the buses in order from 1 to N. Let the buses be B1, 
B2, ...., BN. Also, let us define a good starting day to be any day 
Y in the range [1..D] such that it is possible to start the journey 
on day Y and take all buses in the order from 1 to N before the end 
of day D. Note that we do not require Y to be a multiple of X1, so 
there may be some waiting time involved in the beginning of the 
journey.

For a fixed day Y, let us see if it is a good starting day or not. 
The best strategy would be to take bus B1 as early as possible on 
or after day Y. This is because it would give us more days to take 
subsequent buses. Let us say we took bus B1 on day D1. Now the best 
strategy would be to take bus B2 as early as possible on or after 
day D1. Thus, if we took bus Bi on day Di, it would be optimal to 
take bus Bi+1 as early as possible on or after day Di.

Now we need to find out what is the earliest possible day for 
Bucket to take bus Bi on or after a particular day K. Since bus Bi 
only runs on days that are multiples of Xi, we need to find the 
smallest multiple of Xi greater than or equal to K. This can be 
calculated using the formula ⌈ K / Xi ⌉ * Xi. Thus if bus Bi is 
taken on day Di, then it would be optimal to take bus Bi+1 on day 
Di+1 = ⌈ Di / Xi+1 ⌉ * Xi+1. Thus, day Y is a good starting day if 
DN ≤ D, and this question can be answered in O(N) time.

Test set 1
D can be at most 100, so we can find the latest good starting day 
by using the above approach for each day Y in the range [1..D]. The 
time complexity of this naive algorithm is O(DN).

Test set 2
Now D can be at most 1012, so the naive algorithm would time out. 
Consider the largest good starting day P. Obviously, any day before 
P would be good as well because we can take the buses on the same
days as if we started the journey on day P. Because of this 
observation, we can binary search on the range from 1 to D to find 
the largest good starting day P. The time complexity of the solution 
is O(N log D). Note that we can reduce the time complexity to 
O(N log(D/X1)) by restricting the search to multiples of X1 only.

Alternate solution
It is possible to solve the problem in linear time by working out 
the solution backwards. If we want to start our journey as late as 
possible, we should try to take the last bus BN as late a possible, 
namely, on day DN, which is the largest multiple of XN, less than 
or equal to day D. Similarly, in order to be on time for the last 
bus on day DN, we have to take bus BN-1 no later than on day DN-1, 
which is the largest multiple of XN-1, less than or equal to DN. In 
general, bus Bi should be taken no later than on day Di, which is 
the largest multiple of Xi, less than or equal to Di+1. The last 
calculated value D1 is the answer to the problem.

Note that the largest multiple of Xi that occurs before a day L can 
be calculated in constant time as L - L mod Xi. Therefore, the 
overall time complexity of this solution is O(N).
*/