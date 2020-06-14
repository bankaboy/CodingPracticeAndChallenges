#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array bloomDay, an integer m and an integer k.
We need to make m bouquets. To make a bouquet, you need to use k 
adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the 
bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to 
make m bouquets from the garden. If it is impossible to make m 
bouquets return -1.

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here's the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

Example 4:

Input: bloomDay = [1000000000,1000000000], m = 1, k = 1
Output: 1000000000
Explanation: You need to wait 1000000000 days to have a flower ready for a bouquet.

Example 5:

Input: bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
Output: 9
 
Constraints:
bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n
*/

// Discussion -
// Comments added 

class Solution {
public:
    bool canHarvest(vector<int>& bDay, int harvestDay, int m, int k) {
        int adjacent = 0;
        for (auto bloomDay : bDay) {
            // include adjecent flower if already in bloom 
            adjacent = bloomDay <= harvestDay ? adjacent + 1 : 0;
            // if a bouquet of k flowers made, remove one bouquet
            if (adjacent == k) {
                adjacent = 0;
                --m;
            }
        }
        // are making all bouquets possible with current harvest date?
        return m <= 0;
    }
    int minDays(vector<int>& bDay, int m, int k) {
        // number of total flowers used cannot be bigger than number of flowers given
        if (m * k > bDay.size()) 
            return -1;
        
        auto lo = *min_element(begin(bDay), end(bDay)); // first bloom
        auto hi = *max_element(begin(bDay), end(bDay)); // last bloom
        
        // If all flowers are to be used, have to wait for last blooming (hi) flower
        if (m * k == bDay.size())
            return hi;
        
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            // check if all bouquets can be made by day 'mid'
            // upper bound on number of days to make bouquets
            if (canHarvest(bDay, mid, m, k))
                hi = mid;
            // lower bound on number of days to make bouquets
            else
                lo = mid + 1;
        }
        return lo;
    }
};