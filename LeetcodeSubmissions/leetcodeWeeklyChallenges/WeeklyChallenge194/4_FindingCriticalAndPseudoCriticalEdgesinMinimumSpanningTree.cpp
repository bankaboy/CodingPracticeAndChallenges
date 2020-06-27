/*
Given a weighted undirected connected graph with n vertices numbered 
from 0 to n-1, and an array edges where edges[i] = 
[fromi, toi, weighti] represents a bidirectional and weighted edge 
between nodes fromi and toi. A minimum spanning tree (MST) is a 
subset of the edges of the graph that connects all vertices without 
cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the minimum 
spanning tree (MST) of the given graph. An MST edge whose deletion 
from the graph would cause the MST weight to increase is called a 
critical edge. A pseudo-critical edge, on the other hand, is that 
which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

Example 1:
Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],
[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:
Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:
Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
 
Constraints:
2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti <= 1000
All pairs (fromi, toi) are distinct.
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    std::vector<int> _parent; // index
    std::vector<int> _rank;

    void link(int x, int y) {
        if (_rank[x] > _rank[y]) {
            _parent[y] = x;
        } else {
            _parent[x] = y;
            if (_rank[x] == _rank[y]) {
                ++_rank[y];
            }
        }
    }

public:
    explicit DisjointSet(int n): _parent(std::vector<int>(n, 0)), _rank(std::vector<int>(n, 1)) {
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }
    }

    int find_set(int i) {
        return _parent[i] == i ? _parent[i] : _parent[i] = find_set(_parent[i]);
    }

    void union_sets(int i, int j) {
        link(find_set(i), find_set(j));
    }
};

class Solution {
private:
    int mst(const int n, const std::vector<std::vector<int>>& edges, int forbiddenEdgeIdx = -1, int preEdgeIdx = -1) {
        DisjointSet disjointSet(n);
        int weight = 0;
        if (preEdgeIdx != -1) {
            disjointSet.union_sets(edges[preEdgeIdx][0], edges[preEdgeIdx][1]);
            weight += edges[preEdgeIdx][2];
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (forbiddenEdgeIdx == i) continue;
            if (disjointSet.find_set(edges[i][0]) != disjointSet.find_set(edges[i][1])) {
                disjointSet.union_sets(edges[i][0], edges[i][1]);
                weight += edges[i][2];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (disjointSet.find_set(i) != disjointSet.find_set(0)) {
                return 1e9;
            }
        }
        return weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].emplace_back(i);
        }
        std::sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });
        const auto minWeight = mst(n, edges);
        std::vector<int> criticalEdges;
        std::vector<int> pseudoCriticalEdges;
        for (int i = 0; i < edges.size(); ++i) {
            if (mst(n, edges, i) > minWeight) {
                criticalEdges.emplace_back(edges[i][3]);
            } else if (mst(n, edges, -1, i) == minWeight) {
                pseudoCriticalEdges.emplace_back(edges[i][3]);
            }
        }
        return {criticalEdges, pseudoCriticalEdges};
    }
};