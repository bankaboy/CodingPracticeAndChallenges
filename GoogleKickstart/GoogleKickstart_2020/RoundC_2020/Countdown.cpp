#include <bits/stdc++.h>
using namespace std;

/*
Problem
Avery has an array of N positive integers. The i-th integer of the 
array is Ai.
A contiguous subarray is an m-countdown if it is of length m and 
contains the integers m, m-1, m-2, ..., 2, 1 in that order. For 
example, [3, 2, 1] is a 3-countdown.

Can you help Avery count the number of K-countdowns in her array?

Input
The first line of the input gives the number of test cases, T. T 
test cases follow. 
Each test case begins with a line containing the integers N and K. 
The second line contains N integers. The i-th integer is Ai.

Output
For each test case, output one line containing Case #x: y, where x 
is the test case number (starting from 1) and y is the number of 
K-countdowns in her array.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
2 ≤ K ≤ N.
1 ≤ Ai ≤ 2 × 105, for all i.

Test set 1
2 ≤ N ≤ 1000.

Test set 2
2 ≤ N ≤ 2 × 105 for at most 10 test cases.
For the remaining cases, 2 ≤ N ≤ 1000.

Sample

Input -  
3
12 3
1 2 3 7 9 3 2 1 8 3 2 1
4 2
101 100 99 98
9 6
100 7 6 5 4 3 2 1 100

Output - 
Case #1: 2
Case #2: 0
Case #3: 1

  
In sample case #1, there are two 3-countdowns as highlighted below.
1 2 3 7 9 3 2 1 8 3 2 1
1 2 3 7 9 3 2 1 8 3 2 1

In sample case #2, there are no 2-countdowns.

In sample case #3, there is one 6-countdown as highlighted below.
100 7 6 5 4 3 2 1 100
*/

// My solution - Brute Force
// Works correct on sample case but fails on actual input
int solver(int N, int K, vector<int> A)  {
    int ans = 0;
    for (int i=0;i<N;i++) {
        if (A[i]==K) {
            bool check = true;
            for (int j=i+1;j<i+K;j++) {
                if (A[j-1] != A[j]+1) {
                    check = false;
                    break;
                }
            }
            if (check) { ans++; }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    int n, k, elem;
    for (int i=1;i<=T;i++) {
        cin>>n>>k;
        vector<int> A;
        for (int j=0;j<n;j++) {
            cin>>elem;
            A.push_back(elem);
        }
        cout<<"Case #"<<i<<": "<<solver(n,k,A)<<"\n";
    }
}

/* 
Google Pseudocode - 

  answer_counter = 0
  decreasing_counter = 0
  for (i = 1 to N) {
    if (A[i] == A[i - 1] - 1) {
      decreasing_counter = decreasing_counter + 1
    } else {
      decreasing_counter = 0
    }
    if (A[i] == 1 and decreasing_counter >= K - 1) {
      answer_counter = answer_counter + 1
    }
  }
  print answer_counter
*/

// New code 

int solver(int N, int K, vector<int> A)  {
    int ans = 0, counter = 0;
    for (int i=0;i<N;i++) {
        if (A[i] == A[i - 1] - 1) {
            counter = counter + 1;
        } else {
            counter = 0;
        }
        if (A[i] == 1 and counter >= K - 1) {
            ans = ans + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    int n, k, elem;
    for (int i=1;i<=T;i++) {
        cin>>n>>k;
        vector<int> A;
        for (int j=0;j<n;j++) {
            cin>>elem;
            A.push_back(elem);
        }
        cout<<"Case #"<<i<<": "<<solver(n,k,A)<<"\n";
    }
}