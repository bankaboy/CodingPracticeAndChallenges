/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 
Note:
1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/


// Solution 1 - Sorting by hand
class Solution {
public:
    int distance(vector<int> p) { 
        // If one number is less than other , their sqrt will have same relation
        return p[0]*p[0] + p[1]*p[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<vector<int>> ans;
        vector<int> distances(n,0);
        for (int i=0;i<n;i++) { // calculate distances of all points
            distances[i] = distance(points[i]);
        }
        
        sort(distances.begin(), distances.end()); // sort the distances and find the kth distance
        int kth = distances[K-1];
        
        for (int i=0;i<n;i++) {
            if (distance(points[i])<=kth) { // for every point, if their distance<= kth distance, add to ans
                ans.push_back(points[i]);
            }
        }
        return ans;
    }
};

// Solution 2 - Builtin Sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // sort by using distance comparison as comaprator
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        // return vector slice upto k
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

// Solution 3 - Multimap
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, int> m; // multimap stores keys in increasing order
        for (int i = 0; i < points.size(); ++i)
          m.insert({ points[i][0] * points[i][0] + points[i][1] * points[i][1], i }); // insering dist, index
        vector<vector<int>> res;
        for (auto it = m.begin(); K > 0; ++it, --K) // push first k items into result
            res.push_back(points[it->second]);
        return res;
    }
};
