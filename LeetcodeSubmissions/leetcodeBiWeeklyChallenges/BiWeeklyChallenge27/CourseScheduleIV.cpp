#include<bits/stdc++.h>
using namespace std;

/*
There are a total of n courses you have to take, labeled from 0 to 
n-1.
Some courses may have direct prerequisites, for example, to take 
course 0 you have first to take course 1, which is expressed as a 
pair: [1,0]
Given the total number of courses n, a list of direct prerequisite 
pairs and a list of queries pairs.
You should answer for each queries[i] whether the course 
queries[i][0] is a prerequisite of the course queries[i][1] or not.
Return a list of boolean, the answers to the given queries.
Please note that if course a is a prerequisite of course b and 
course b is a prerequisite of course c, then, course a is a 
prerequisite of course c.

Example 1:
Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.

Example 2:
Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites and each course is independent.

Example 3:
Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]

Example 4:
Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
Output: [false,true]

Example 5:
Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
Output: [true,false,true,false]
 
Constraints:
2 <= n <= 100
0 <= prerequisite.length <= (n * (n - 1) / 2)
0 <= prerequisite[i][0], prerequisite[i][1] < n
prerequisite[i][0] != prerequisite[i][1]
The prerequisites graph has no cycles.
The prerequisites graph has no repeated edges.
1 <= queries.length <= 10^4
queries[i][0] != queries[i][1]
*/

// Attempt - BFS between query nodes
// Time limit exceeded
class Solution {
public:
    bool bfs(int n, vector<vector<int>> adj, int s, int d) {
        if (s==d) { return true; }
        vector<bool> visited(n, false);
        
        queue<int> q;
        visited[s] = true; 
        q.push(s);
        
        while(!q.empty()) {
            s = q.front();
            q.pop();
            for (auto i=adj[s].begin(); i!=adj[s].end();i++) {
                if (*i==d) { return true; }
                if (!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(n, vector<int>());
        for (auto &p:pre) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> ans;
        for (vector<int> query: q) {
            // second element is prerequisite of first
            ans.push_back(bfs(n, adj, query[1], query[0]));
        }
        return ans;
    }
};

// Discussion
/*
This problem is about check if 2 vertices are connected in directed 
graph. Floyd-Warshall O(n^3) is an algorithm that will output the 
minium distance of any vertices. We can modified it to output if 
any vertices is connected or not.
*/
class Solution {
    vector<bool> checkIfPrerequisite(int n,  vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>> connected(n,vector<bool>(n));
        for (vector<int> p : pre)
            connected[p[0]][p[1]] = true; // p[0] -> p[1]
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    // direct connection or via one vertex
                    connected[i][j] = connected[i][j] || connected[i][k] && connected[k][j];
        vector<bool> ans;
        for (vector<int> q : queries)
            ans.push_back(connected[q[0]][q[1]]);
        return ans;
    }
};

// Discusion - Faster
class Solution {
    vector<vector<int>>dp;
    bool dfs(unordered_map<int, vector<int>>& mp, int a, int b) {
        
        if (dp[a][b] != -1)
            return dp[a][b];
        
        for (int i = 0; i < mp[a].size(); i++) {
            if (mp[a][i] == b) return dp[a][b] = 1;
            if (dfs(mp, mp[a][i], b)) return dp[mp[a][i]][b] = 1;
        }
        
        return dp[a][b] = 0;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        unordered_map<int, vector<int>>mp;
        
        dp.resize(n, vector<int>(n, -1));
        for (int i = 0; i < prerequisites.size(); i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dp[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
            
        vector<bool>res;
        for (int i = 0; i < queries.size(); i++) {
            bool p = dfs(mp, queries[i][1], queries[i][0]);
            res.push_back(p);
        }
        
        return res;
    }
};