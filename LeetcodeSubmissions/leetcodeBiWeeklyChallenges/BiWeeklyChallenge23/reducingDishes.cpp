/*
Problem Statement - 

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]
Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35

Discussion - 

1.) It's easy to see we want to spend most time on highest number so we sort the satisfatction.
2.) We might like to stop at some point if a satisfaction becomes too negative.
3.) We can calculate in linear time that point using prefix sums as each time we consider the next satisfaction, increasing all previous times with 1 is the same as adding the prefix sum so far.
*/

int maxSatisfaction(vector<int>& s) {
    sort(s.rbegin(), s.rend()); // sort descending
    int best = 0; // best result
    int prefixSum = 0; // sum of all satisfaction from biggest to s[i]
    int cur = 0; //result after each iteration
    for (int i = 0; i < s.size(); i++) {
        prefixSum += s[i]; // add this to prefixSum
        cur += prefixSum; // cur so far (we add +1 time to all previous)
        best = max(best, cur); // is cur better?
    }
    return best;
}