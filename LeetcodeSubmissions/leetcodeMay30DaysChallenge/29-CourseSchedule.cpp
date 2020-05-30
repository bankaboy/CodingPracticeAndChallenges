/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is 
expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 
Constraints:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/
 
// Just check if topological sorting is possible - Taken from cormen

class Solution {
public:
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        // num is the number of vertices
        // pre is a list of egdes
        // change it to list of adjacency lists adj
        vector<vector<int>> adj(num, vector<int>());
        vector<int> degree(num,0);
        for (auto &p:pre) {
            // the second element is the prerequisite of the first one
            // edge goes from second to first
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++; // number of prerequisites for the first element
        }
        queue<int> q;
        for (int i=0;i<num;i++) {
            // Put all the vertices with no prerequisites in a queue
            // start traversal from base nodes (that have no indegree)
            if (degree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            num--; // a vertex has been completed(popped out of queue)
            for (auto next:adj[curr]) {
                if(--degree[next] == 0) { // each course will have one prerequisite resolved in each iteration
                    q.push(next); 
                    // push into queue if all prerequisites completed, since it can now be used for a vertex 
                    // for which it is a prerequisite
                }
            }
        }
        // check if all vertices have been reached once (won't happen if cycle, num<0) 
        return num == 0;
    }
};



