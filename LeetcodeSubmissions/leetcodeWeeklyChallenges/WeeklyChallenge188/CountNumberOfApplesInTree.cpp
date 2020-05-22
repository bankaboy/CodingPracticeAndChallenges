#include<bits/stdc++.h>
using namespace std;

/*
Problem - 

Given an undirected tree consisting of n vertices numbered from 0 
to n-1, which has some apples in their vertices. You spend 1 second
to walk over one edge of the tree. Return the minimum time in 
seconds you have to spend in order to collect all apples in the 
tree starting at vertex 0 and coming back to this vertex.
The edges of the undirected tree are given in the array edges, 
where edges[i] = [fromi, toi] means that exists an edge connecting 
the vertices fromi and toi. Additionally, there is a boolean array 
hasApple, where hasApple[i] = true means that vertex i has an apple, 
otherwise, it does not have any apple.

Example 1:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

Example 3:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0

Constraints:
1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n
*/


// My solution - do bfs and add to count if node has apple
class Solution {
public:
    int count = 0;
    int vis[100000];
    
    void bfs(int s, vector<vector<int>> matrix, int n, vector<bool> hasApple) { 
        queue<int> Q;
        int count = 0;
        
        Q.push(s);
        vis[s] = 1;
        int p = Q.front();
        Q.pop();
        
        while (p!=0) {
            for (int i=1;i<n;i++) {
                if (matrix[p][i]!=0 && vis[i]==0) {
                    Q.push(i);
                    vis[i] = 1;
                    if (hasApple[i]) { count+=1; }
                }
            }
            for (int i=1;i<=n;i++) {
                if (vis[i]==0) {
                    bfs(i,matrix,n,hasApple);
                }
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        for (vector<int> edge: edges) {
            matrix[edge[0]][edge[1]] = 1;
            matrix[edge[1]][edge[0]] = 1;
        }
        bfs(0, matrix, n, hasApple);
        return count;
    }
};


/*
Discussion - 

Key idea
Whenever you are at a node, say p, you will collect all apples in 
p’s subtree before returning back to the original root. This will 
avoid traveling the same path multiple times.
Say, root is where we start, p is a node in the tree and p has two 
children child1 & child2.
root -> p -> child1 -> p -> child2 -> p -> rootis always going to 
be better than
root-> p -> child1 -> p -> root -> p -> child2 -> p -> root.

So now it becomes a simple graph traversal problem, particularly 
DFS where we visit all children of the node first and then go back 
the other nodes.

Algorithm

1. Because you have the list of edges, construct the graph first to 
have a better representation of the graph.
2. For each node, check if any of its children have apples and find 
the total cost in terms of time in seconds of collecting those.
3. If there is at least one child with an apple, then we have to 
collect it. So we will also have to add the cost (time required) of 
reaching that node.
4. return the total time.
*/

class Solution {
public:
    unordered_map<int, vector<int>> g; // to store the graph
    
    void createGraph(vector<vector<int>>& edges) {
      for (auto e: edges) {
        g[e[0]].push_back(e[1]); // adjecency list representation
      }
    }
  
    int dfs(int node, int myCost, vector<bool>& hasApple) {
      int childrenCost = 0; // cost of traversing all children. 
      for (auto x: g[node]) { 
        childrenCost += dfs(x, 2, hasApple);  // check recursively for all apples.
      }

      if (childrenCost == 0 && hasApple[node] == false) {
	  // If no children has apples, then we won't traverse the subtree, so cost will be zero.
	  // similarly, if current node also does not have the apple, we won't traverse this branch at all, so cost will be zero.
        return 0;
      }
	  
	  // Children has at least one apple or the current node has an apple, so add those costs.
      return (childrenCost + myCost);
    }
  
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      createGraph(edges); // construct the graph first.
      return dfs(0, 0, hasApple); // cost of reaching the root is 0. For all others, its 2.
    }
};

// top solution - 
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<int> E[101010];
vector<bool> H;
int ret;
class Solution {
public:
	
	int dfs(int cur,int pre) {
		int take=H[cur];
		FORR(e,E[cur]) if(e!=pre) take |= dfs(e,cur);
		if(take&&cur) ret+=2;
		return take;
	}

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        H=hasApple;
        int N=H.size();
        int i;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		
		ret=0;
		dfs(0,-1);
		return ret;
        
    }
};


