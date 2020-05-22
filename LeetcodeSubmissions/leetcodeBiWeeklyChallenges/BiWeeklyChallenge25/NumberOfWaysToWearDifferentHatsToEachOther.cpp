#include<bits/stdc++.h>
using namespace std;

/*
Problem -

There are n people and 40 types of hats labeled from 1 to 40.
Given a list of list of integers hats, where hats[i] is a list of 
all hats preferred by the i-th person.
Return the number of ways that the n people wear different hats to 
each other.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.

Example 2:
Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats
(3,5), (5,3), (1,3) and (1,5)

Example 3:
Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.

Example 4:
Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
Output: 111

Constraints:
n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] contains a list of unique integers.
*/

/*
Disscussion
Since we have less persons and more hats, it would be better if we 
re-organize the information structure. Instead of recording the hat 
labels for each person, recording the person labels for each hat 
will benefit us later in the bit-masking.
*/

class Solution {
public:
    
    int numberWays(vector<vector<int>>& hats) {
		// n: number of persons
		// h: number of hats
		// Time Complexity: O(2^n * h)
		// Space Complexity: O(2^n)
		
        // hats -> persons
        vector<vector<int>> persons(40);
        const int n(hats.size()), mod(1e9+7);
		
		// masks range from 00...0 to 11...1 (n-digit binary number)
		// i-th digit represents whether i-th person has already had a hat
		// Base case: no one has a hat at first
        vector<int> masks(1 << n);
        masks[0] = 1;
        
		// re-organize
        for (int i = 0; i < n; ++i)
            for (const int& h: hats[i])
                persons[h - 1].push_back(i);
        
        for (int i = 0; i < 40; ++i)                    // hats
            for (int j = (1 << n) - 1; j >= 0; --j)     // masks
                for (const int& p: persons[i])          // persons
					// if the current state j implies that p-th person hasn't had a hat yet
					// we can give the i-th hat to that person, and update the state
                    if ((j & (1 << p)) == 0) {
                        masks[j | (1 << p)] += masks[j];
                        masks[j | (1 << p)] %= mod;
                    }
        // return the state that each person has a hat
        return masks[(1 << n) - 1];
    }
};
