/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection 
of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

Note:
0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method 
signature.
*/

// Try 1 - Check each interval in A with each in B - Misses subset cases

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        for (vector<int> inv1 : A) {
            for (vector<int> inv2 : B) {
                if (inv1[1]>=inv2[0] && inv1[1]<=inv2[1] && inv1[0]<=inv2[0]) { // end of inv1 lies in inv2 and inv1 
                // is not a subset of inv2 i.e inv2[0]<inv1[0]
                    ans.push_back({inv2[0], inv1[1]}); // interval from start of inv2 to end of inv1
                } else if (inv2[1]>=inv1[0] && inv2[1]<=inv1[1] && inv2[0]<=inv1[0]) { // end of inv2 lies in inv1 and 
                // inv2 is not a subset of inv1 i.e inv1[0]<inv2[0]
                    ans.push_back({inv1[0], inv2[1]}); // interval from start of inv1 to end of inv1
                }
            }
        }
        return ans;
    }
};

// Set intersection theory

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0,j = 0, n = A.size(), m = B.size();
        while (i<n && j<m) {
            // check if A[i] intersects B[j]
            // lo - the startpoint of the intersection
            // hi endpoint of the intersection
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo<=hi) {
                ans.push_back({lo,hi});
            }
            
            // Remove the interval with smallest endpoint
            if (A[i][1]<B[j][1])
                i++;
            else 
                j++;
        }
        return ans;
    }
};
