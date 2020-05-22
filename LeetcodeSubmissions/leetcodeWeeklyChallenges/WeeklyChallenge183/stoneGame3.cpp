/*
Problem statement - 

Alice and Bob continue their games with piles of stones. There are 
several stones arranged in a row, and each stone has an associated 
value which is an integer given in the array stoneValue.
Alice and Bob take turns, with Alice starting first. On each 
player's turn, that player can take 1, 2 or 3 stones from the first 
remaining stones in the row.
The score of each player is the sum of values of the stones taken. 
The score of each player is 0 initially.
The objective of the game is to end with the highest score, and the 
winner is the player with the highest score and there could be a tie. 
The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.
Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if 
they end the game with the same score.

Input: values = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take 
three piles and the score become 6. Now the score of Bob is 7 and 
Bob wins.

Input: values = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move
to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move 
Bob's score becomes 5. The next move Alice will take the pile with 
value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move 
Bob's score becomes 3. The next move Alice will take the pile with 
value = -9 and also lose.
Remember that both play optimally so here Alice will choose the 
scenario that makes her win.

Input: values = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a 
draw if she decided to choose all the first three piles, otherwise 
she will lose.

Input: values = [1,2,3,-1,-2,-3,7]
Output: "Alice"

Input: values = [-1,-2,-3]
Output: "Tie"
*/

/*
Solution 1 - 

Solution 1: DP
dp[i] means, if we ignore before A[i],
what's the highest score that Alex can win over the Bob？

There are three option for Alice to choose.
Take A[i], win take - dp[i+1]
Take A[i] + A[i+1], win take - dp[i+2]
Take A[i] + A[i+1] + A[i+2], win take - dp[i+3]
dp[i] equals the best outcome of these three solutions.


Complexity
Time O(N^2)
Space O(N)
*/

#include<iostream>
#include<vector>
using namespace std;
string stoneGameIII(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n, -1e9);
    for (int i = n - 1; i >= 0; --i) {
        for (int k = 0, take = 0; k < 3 && i + k < n; ++k) {
            take += A[i + k];
            dp[i] = max(dp[i], take - (i + k + 1 < n ? dp[i + k + 1] : 0));
        }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
}

/*
Solution 2 - 

We don't need O(N) space.
We only need last 3 results: dp[i+1],dp[i+2] and dp[i+3].
Time O(N), space O(1)
*/

string stoneGameIII(vector<int>& A) {
    vector<int> dp(4);
    for (int i = A.size() - 1; i >= 0; --i) {
        dp[i % 4] = -1e9;
        for (int k = 0, take = 0; k < 3 && i + k < A.size(); ++k)
            dp[i % 4] = max(dp[i % 4], (take += A[i + k]) - dp[(i + k + 1) % 4]);
    }
    return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
}