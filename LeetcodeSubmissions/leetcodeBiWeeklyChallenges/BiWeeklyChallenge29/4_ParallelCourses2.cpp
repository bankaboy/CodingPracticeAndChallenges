/*
Given the integer n representing the number of courses at 
some university labeled from 1 to n, and the array 
dependencies where dependencies[i] = [xi, yi]  represents 
a prerequisite relationship, that is, the course xi must 
be taken before the course yi.  Also, you are given the 
integer k.

In one semester you can take at most k courses as long as 
you have taken all the prerequisites for the courses you 
are taking.

Return the minimum number of semesters to take all courses. 
It is guaranteed that you can take all courses in some way.


Example 1:
Input: n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
Output: 3 
Explanation: The figure above represents the given graph. 
In this case we can take courses 2 and 3 in the first 
semester, then take course 1 in the second semester and 
finally take course 4 in the third semester.

Example 2:
Input: n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], 
k = 2
Output: 4 
Explanation: The figure above represents the given graph. 
In this case one optimal way to take all courses is: take 
courses 2 and 3 in the first semester and take course 4 in 
the second semester, then take course 1 in the third 
semester and finally take course 5 in the fourth semester.

Example 3:
Input: n = 11, dependencies = [], k = 2
Output: 6

Constraints:
* 1 <= n <= 15
* 1 <= k <= n
* 0 <= dependencies.length <= n * (n-1) / 2
* dependencies[i].length == 2
* 1 <= xi, yi <= n
* xi != yi
* All prerequisite relationships are distinct, that is, 
  dependencies[i] != dependencies[j].
* The given graph is a directed acyclic graph.
*/

#include<bits/stdc++.h>
using namespace std;

// My solution - 
// copied parallel course 1 sol and tried to modify
class Solution {
    public int minNumberOfSemesters(int N, int[][] relations, int k) {
        if (relations.length == 0) {
            return N/k+1;
        }
        
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        int[] inDegree = new int[N + 1];
        
        for(int i = 1; i <= N; i++) {
            graph.put(i, new HashSet<>());
        }
        for(int[] edge : relations) {
            if(graph.get(edge[0]).add(edge[1])) {
                inDegree[edge[1]]++;
            }
        }   
        
        Queue<Integer> q = new LinkedList<>();
        int semester = 0, course = 0;
        for(int i = 1; i <= N ; i++) {
            if(inDegree[i] == 0) {
                q.add(i);           
            }
        }
        
        while(q.size() > 0 && k>0) {
            int sz = q.size();
            course += sz;
            for(int i = 0; i < sz; i++) {
                int curr = q.poll();
                for(int neighbor : graph.get(curr)) {
                    inDegree[neighbor]--;
                    if(inDegree[neighbor] == 0) {
                        q.add(neighbor);
                    }
                }               
            }
            semester++;
            k--;
        }
        return course == N ? semester : -1;
    }
}

// Discussion 
bool func(int& a, int& b){
    return a>b;
}
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int m=dependencies.size();
        if(m==0) return (n%k==0)?n/k:n/k+1;
        
        unordered_map<int, vector<int>> grid;
        vector<int> indegree(n, 0);
        for(vector<int> dep : dependencies){
            grid[dep[0]].push_back(dep[1]);
            indegree[dep[1]-1]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++)
            if(indegree[i]==0)
                q.push(i+1);
        
        int semesters=0;
        
        while(!q.empty()){
            semesters++;
            queue<int> qtemp;
            for(int i=0; i<k; i++){
                if(q.empty()) break;
                int elem=q.front();
                q.pop();
                
                sort(grid[elem].begin(), grid[elem].end(), func);
                for(int val : grid[elem]){
                    indegree[val-1]--;
                
                    if(indegree[val-1]==0)
                        qtemp.push(val);
                }
            }
            while(!qtemp.empty()){
                q.push(qtemp.front());
                qtemp.pop();
            }
        }
        return semesters;
    }
};