#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers cost and an integer target. Return the 
maximum integer you can paint under the following rules:

The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
The total cost used must be equal to target.
Integer does not have digits 0.
Since the answer may be too large, return it as string.

If there is no way to paint any integer given the condition, 
return "0".

Example 1:
Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
Output: "7772"
Explanation:  The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "997", but "7772" is the largest number.
Digit    cost
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5

Example 2:
Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
Output: "85"
Explanation: The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.

Example 3:
Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
Output: "0"
Explanation: It's not possible to paint any integer with total cost equal to target.

Example 4:
Input: cost = [6,10,15,40,40,40,40,40,40], target = 47
Output: "32211"
 
Constraints:
cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000
*/

/* My solution - 
Modify target sum code to generate numbers ans store instead of
storing possible combinations - failed
*/
class Solution {
    void findNumbers(vector<int>& ar, int sum, vector<string>& res, string &r, int i) { 
        // If  current sum becomes negative 
        if (sum < 0) 
            return;   
        // if we get exact answer 
        if (sum == 0) { 
            res.push_back(r); 
            return; 
        } 
    
        // Recur for all remaining elements that 
        // have value smaller than sum. 
        while (i < ar.size() && sum - ar[i] >= 0) { 
        
            // Till every element in the array starting 
            // from i which can contribute to the sum 
            r.insert(r.begin(), char(i+1)); // add them to list 
    
            // recur for next numbers 
            findNumbers(ar, sum - ar[i], res, r, i); 
            i++; 
    
            // remove number from list (backtracking) 
            r.pop_back(); 
        } 
    }     
    vector<string> combinationSum(vector<int>& ar, int sum) { 
        // sort input array 
        sort(ar.begin(), ar.end()); 
    
        // remove duplicates 
        ar.erase(unique(ar.begin(), ar.end()), ar.end()); 
    
        string r; 
        vector<string> res; 
        findNumbers(ar, sum, res, r, 0); 
    
        return res; 
    }
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> result = combinationSum(cost, target);
        int n = result.size();
        return *max_element(result.begin(), result.end());
    }
};

// Discussion - 

// Top-Down

string dp[5001] = {};
string largestNumber(vector<int>& cost, int t) {
    if (t <= 0)
        return t == 0 ? "" : "0";
    if (dp[t].empty()) {
        dp[t] = "0";
        for (int n = 1; n <= 9; ++n) {
            auto res = largestNumber(cost, t - cost[n - 1]);
            if (res != "0" && res.size() + 1 >= dp[t].size())
                dp[t] = to_string(n) + res;
        }
    }
    return dp[t];
}

// Bottom-Up

string largestNumber(vector<int>& cost, int t) {
    vector<string> dp(t + 1, "0");
    dp[t] = "";
    for (int i = t - 1; i >= 0; --i) {
        for (int n = 1; n <= 9; ++n) {
            int val = i + cost[n - 1];
            if (val <= t && dp[val] != "0")
                if (dp[val].size() + 1 >= dp[i].size())
                    dp[i] = to_string(n) + dp[val];
        }
    }
    return dp[0];
}

// O(n)

string largestNumber(vector<int>& cost, int t) {
    vector<pair<int, int>> dp(t + 1);
    dp[t].second = 1;
    for (int i = t - 1; i >= 0; --i)
        for (int n = 0; n <= 8; ++n) {
            int val = i + cost[n];
            if (val <= t && dp[val].second != 0)
                if (dp[val].second + 1 >= dp[i].second)
                    dp[i] = { n, dp[val].second + 1};
        }
    if (dp[0].second == 0)
        return "0";
    string res;
    for (auto i = 0; i < t; i += cost[dp[i].first])
        res.push_back(dp[i].first + '1');
    return res;
}