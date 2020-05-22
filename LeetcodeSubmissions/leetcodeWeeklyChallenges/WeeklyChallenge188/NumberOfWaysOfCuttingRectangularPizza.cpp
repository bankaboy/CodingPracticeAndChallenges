#include<bits/stdc++.h>
using namespace std;

/* 
Problem - 

Given a rectangular pizza represented as a rows x cols matrix 
containing the following characters: 'A' (an apple) and '.' 
(empty cell) and given the integer k. You have to cut the pizza
into k pieces using k-1 cuts. 
For each cut you choose the direction: vertical or horizontal, then 
you choose a cut position at the cell boundary and cut the pizza 
into two pieces. If you cut the pizza vertically, give the left 
part of the pizza to a person. If you cut the pizza horizontally, 
give the upper part of the pizza to a person. Give the last piece 
of pizza to the last person.
Return the number of ways of cutting the pizza such that each piece 
contains at least one apple. Since the answer can be a huge number, 
return this modulo 10^9 + 7.

Example 1:
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:
Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:
Input: pizza = ["A..","A..","..."], k = 1
Output: 1

Constraints:

1 <= rows, cols <= 50
rows == pizza.length
cols == pizza[i].length
1 <= k <= 10
pizza consists of characters 'A' and '.' only.
*/

/*
Discussion - 
Let dp[i][j][k] be the answer for the subproblem with k pieces and 
subarray from A[i][j] to A[M-1][N-1].
For each i, j, k, we should try:

Slice horizontally at row t where i < t < M. 
dp[i][j][k] += sum( dp[t][j][k - 1] | i < t < M && slicing at row t 
is valid )
Slice vertically at column t where j < t < N. 
dp[i][j][k] += sum( dp[i][t][k - 1] | j < t < N && slicing at column 
t is valid)
dp[i][j][k] = sum( dp[t][j][k - 1] | i < t < M && slicing at row t 
is valid ) + sum( dp[i][t][k - 1] | j < t < N && slicing at column 
t is valid)
dp[i][j][1] = 1
To check if slicing at row or column t is valid, we can precompute 
an array cnt where cnt[i][j] is the number of apples in the 
rectangle from A[i][j] to A[M-1][N-1].

If we slice at row t, then cnt[i][j] == cnt[t][j] means that there 
is no apples in rectangle A[i][j] to A[t][N-1], we should skip this 
t since it's an invalid slice.

cnt[t][j] == 0 means there is no apply in rectangle A[t][j] to A[M-1][N-1], we should break at t since further extending t won't results in any valid slice.

Time: O(MNK * max(M, N))
Space: O(MNK)
*/
class Solution {
    void add(long &a, long &b) { a = (a + b) % ((int) 1e9+7); }
public:
    int ways(vector<string>& A, int K) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> cnt(M + 1, vector<int>(N + 1));
        for (int i = M - 1; i >= 0; --i) {
            int s = 0;
            for (int j = N - 1; j >= 0; --j) {
                s += A[i][j] == 'A';
                cnt[i][j] = cnt[i + 1][j] + s;
            }
        }
        vector<vector<vector<long>>> dp(M + 1, vector<vector<long>>(N + 1, vector<long>(K + 1)));
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[i][j][1] = 1;
                for (int k = 2; k <= K; ++k) {
                    for (int t = i + 1; t < M; ++t) {
                        if (cnt[i][j] == cnt[t][j]) continue;
                        if (cnt[t][j] == 0) break;
                        add(dp[i][j][k], dp[t][j][k - 1]);
                    }
                    for (int t = j + 1; t < N; ++t) {
                        if (cnt[i][j] == cnt[i][t]) continue;
                        if (cnt[i][t] == 0) break;
                        add(dp[i][j][k], dp[i][t][k - 1]);
                    }
                }
            }
        }
        return dp[0][0][K];
    }
};


// top solution - 

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,S[101][101];
ll mo=1000000007;
ll memo[51][51][11];

class Solution {
public:
	ll hoge(int H,int W,int k) {
		if(memo[H][W][k]>=0) return memo[H][W][k];
		if(k==1) {
			return S[H][W]>0;
		}
		ll ret=0;
		
		for(int w=1;w<W;w++) {
			if(S[H][w]>0&&S[H][W]-S[H][w]>0) ret+=hoge(H,w,k-1);
		}
		for(int h=1;h<H;h++) {
			if(S[h][W]>0&&S[H][W]-S[h][W]>0) ret+=hoge(h,W,k-1);
		}
        return memo[H][W][k]=ret%mo;
	}
    int ways(vector<string>& pizza, int k) {
        H=pizza.size();
        W=pizza[0].size();
        reverse(ALL(pizza));
        FORR(p,pizza) reverse(ALL(p));
        ZERO(S);
        int y,x;
        FOR(y,H) FOR(x,W) S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+(pizza[y][x]=='A');
        MINUS(memo);
        
        return hoge(H,W,k);
        
    }
};
