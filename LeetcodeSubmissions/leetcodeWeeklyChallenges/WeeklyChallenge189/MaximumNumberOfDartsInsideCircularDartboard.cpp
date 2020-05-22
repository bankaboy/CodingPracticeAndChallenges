#include<bits/stdc++.h>
using namespace std;

/*
You have a very large square wall and a circular dartboard placed 
on the wall. You have been challenged to throw darts into the board 
blindfolded. Darts thrown at the wall are represented as an array 
of points on a 2D plane. 
Return the maximum number of points that are within or lie on any 
circular dartboard of radius r.

Example 1:
Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
Output: 4
Explanation: Circle dartboard with center in (0,0) and radius = 2 contain all points.

Example 2:
Input: points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
Output: 5
Explanation: Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).

Example 3:
Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
Output: 1

Example 4:
Input: points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
Output: 4

Constraints:
1 <= points.length <= 100
points[i].length == 2
-10^4 <= points[i][0], points[i][1] <= 10^4
1 <= r <= 5000
*/

/* 
My solution - Wrong Answer
Take the mean of all the given points and check if points lie on it.
Problem asks for any circle of radius r
*/
class Solution {
    bool insideCircle(vector<int> point, pair<int,int> center, int r) {
        int delX = point[0]-center.first;
        int delY = point[1]-center.second;
        int equation = (delX*delX)+(delY*delY);
        return equation<=(r*r);
    }
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int x = 0, y = 0, n = points.size();
        for(vector<int> point : points) {
            x += point[0];
            y += point[1];
        }
        pair<int,int> center = {x/n, y/n};
        cout<<center.first<<" "<<center.second;
        int ans = 0;
        for (vector<int> point: points) {
            if (insideCircle(point, center, r)) {
                ans++;
            }
        }
        return ans;
    }
};

/*
Discussion - 
This is the "disk partial covering problem" in the literature, which 
can be solved with angular sweep. 
The basic idea is: for each point, place it on the circle boundary. 
Then sweep (or "rotate") the circle around this point to see which 
direction contains the most points. Do this for all points and we 
find the global max.
The sweep around a point p can be done in O(nlogn) time by: (a) for 
another point q != p, find the entering angle such that when we 
place the circle at this angle, this circle contains q (i.e., q 
enters the circle); (b) similarly, find the exit angle such that 
when we further increase the angle, the point q will not be inside 
the circle anymore; and (c) sort the angles so that we can 
march/sweep around all other points in linear time.
Therefore, it takes O(nlogn) time to find the best circle for a 
fixed anchor point p, and then multiply that by O(n) to perform the 
check for all points. The total time is O(n^2 log n).
I draw the below ugly picture for illustration, in case you failed 
to find the link I mentioned above (from Geek***geeks)
*/
class Solution {
public:
    int numPoints(vector<vector<int>>& p, int r) {
        int n = p.size();
        vector<vector<double>> dist(n, vector<double>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                dist[i][j] = dist[j][i] = sqrt((p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]));
            }
        }
        
        int res = 1;
        for (int i=0; i<n; ++i) {
            vector<pair<double, bool>> angles;
            
            for (int j=0; j<n; ++j) {
                if (j != i && dist[i][j] <= 2 * r) {
                    double A = atan2(p[j][1] - p[i][1], p[j][0] - p[i][0]);
                    double B = acos(dist[i][j] / (2.0 * r));
                    double alpha = A-B; 
                    double beta = A+B; 
                    angles.push_back(make_pair(alpha, false)); // "false" means this point is entering
                    angles.push_back(make_pair(beta, true)); // "true" means this point is exiting
                }
            }
            
            sort(angles.begin(), angles.end()); 
            
            int cnt = 1;
            for (auto it=angles.begin(); it!=angles.end(); ++it) 
            { 
                if ((*it).second == false) cnt++; 
                else cnt--; 

                res = max(res, cnt);
            } 
        }
        
        return res;
    }

};