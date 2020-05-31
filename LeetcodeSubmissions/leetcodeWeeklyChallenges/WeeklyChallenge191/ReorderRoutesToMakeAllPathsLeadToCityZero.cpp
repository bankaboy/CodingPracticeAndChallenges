#include<bits/stdc++.h>
using namespace std;

/*
There are n cities numbered from 0 to n-1 and n-1 roads such that 
there is only one way to travel between two different cities 
(this network form a tree). Last year, The ministry of transport 
decided to orient the roads in one direction because they are too 
narrow.
Roads are represented by connections where connections[i] = [a, b] 
represents a road from city a to b.
This year, there will be a big event in the capital (city 0), and 
many people want to travel to this city.
Your task consists of reorienting some roads such that each city 
can visit the city 0. Return the minimum number of edges changed.
It's guaranteed that each city can reach the city 0 after reorder.

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

Constraints:
2 <= n <= 5 * 10^4
connections.length == n-1
connections[i].length == 2
0 <= connections[i][0], connections[i][1] <= n-1
connections[i][0] != connections[i][1]
*/

/* My Solution - return back edge count of root using dfs
We can solve this problem using DFS. we start dfs at root of given 
tree and at each node we store its distance from starting node 
assuming all edges as undirected and we also store number of edges 
which need to be reversed in the path from starting node to current 
node, let’s denote such edges as back edges so back edges are those 
which point towards the node in a path. With this dfs, we also 
calculate total number of edge reversals in the tree. After this 
computation, at root we can calculate ‘number of edge reversal to 
reach every other node’ as follows,
Let total number of reversals in tree when root is chosen as 
starting node for dfs is R then if we want to reach every other 
node from node i we need to reverse all back edges from path node 
i to starting node and we also need to reverse all other back edges 
other than node i to starting node path. First part will be 
(distance of node i from starting node – back edges count at node i) 
because we want to reverse edges in path from node i to starting 
node it will be total edges (i.e. distance) minus back edges from 
starting node to node i (i.e. back edge count at node i). The 
second part will be (total edge reversal or total back edges of 
tree R – back edge count of node i).
*/

class Solution {
public:
    int dfs (vector<pair<int, int>> g[], pair<int,int> disRev[], bool visit[], int u) {
        visit[u] = true;
        int totalRev = 0;
        
        for (int i = 0; i < g[u].size(); i++) { 
            int v = g[u][i].first; 
            if (!visit[v]) { 
                // distance of v will be one more than distance of u 
                disRev[v].first = disRev[u].first + 1; 
  
                // initialize back edge count same as 
                // parent node's count 
                disRev[v].second = disRev[u].second; 
  
                // if there is a reverse edge from u to i, 
                // then only update 
                if (g[u][i].second) { 
                    disRev[v].second = disRev[u].second + 1; 
                    totalRev++; 
                } 
                totalRev += dfs(g, disRev, visit, v); 
            } 
        } 
  
        // return total reversal in subtree rooted at u 
        return totalRev;
    }
    
    int minReorder(int V, vector<vector<int>>& conn) {
        
        vector<pair<int,int>> g[V];
        pair<int,int> disRev[V];
        bool visit[V];
        int u, v;
        
        for (int  i=0; i<V-1;i++) {
            u = conn[i][0];
            v = conn[i][1];
            g[u].push_back(make_pair(v,1)); // path from u to v
            g[v].push_back(make_pair(u,0)); // 0 weight path from v to u
        }
        
        for (int i=0; i<V; i++) {
            visit[i] = false;
            disRev[i].first = disRev[i].second = 0;
        }
        
        int root = 0;
        int totalRev = dfs(g, disRev, visit, root);
        
        return totalRev+disRev[0].first-2*disRev[0].second;
    }
};

/* Discussion - 
Based on the problem description, we have a tree, and node zero is 
the root.
However, the direction can point either from a parent to a child 
(positive), or from a child to its parent (negative). To solve the 
problem, we traverse the tree and count edges that are directed 
from a parent to a child. This direction needs to be changed to 
arrive at zero node.
In the code below, I am using the adjacency list, and using a sign 
to indicate the direction. If it is positive, then we are traveling 
from zero, so we need to change the direction (change += (to > 0)).
Note that we cannot detect the direction for zero (-0 == 0), but it 
does not matter as we start our traversal from zero
*/

// Count the number of edges going from parent to child, 
// taking 0 as root, and having a +ve path from a to b and -ve
// path from b to a

class Solution {
public:
    int dfs(vector<vector<int>> &al, vector<bool> &visited, int from) {
        auto change = 0;
        visited[from] = true;
        for (auto to : al[from])
            if (!visited[abs(to)])
                change += dfs(al, visited, abs(to)) + (to > 0);
        return change;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);
        vector<bool> visited(n);
        for (auto &c : connections) {
            al[c[0]].push_back(c[1]);
            al[c[1]].push_back(-c[0]);
        }
        return dfs(al, visited, 0);
    }
};