#include<bits/stdc++.h>
using namespace std;

/*
You are given a tree with n nodes numbered from 0 to n-1 in the 
form of a parent array where parent[i] is the parent of node i. 
The root of the tree is node 0.

Implement the function getKthAncestor(int node, int k) to return 
the k-th ancestor of the given node. If there is no such ancestor, 
return -1.

The k-th ancestor of a tree node is the k-th node in the path from 
that node to the root.

 

Example:

Input:
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

Output:
[null,1,0,-1]

Explanation:
TreeAncestor treeAncestor = new TreeAncestor(7, 
[-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the 
grandparent of 5
treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is 
no such ancestor
 

Constraints:
1 <= k <= n <= 5*10^4
parent[0] == -1 indicating that 0 is the root node.
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5*10^4 queries.
*/

// Attempt 1 - convert pointer code to array code
class TreeAncestor {
public:
    vector<int> parents;
    vector<int> tree;
    int temp;
    TreeAncestor(int n, vector<int>& parent) {
        parents = parent;
        for(int i=0;i<n;i++) {
            tree.push_back(i);
        }
    }
    
    int getKthAncestor(int node, int k, int root=0) {
        if (tree.empty()) {
            return -1;
        }
        if (tree[root] == node || (temp = getKthAncestor(node, k, 2*root+1))
           || (temp = getKthAncestor(node, k, 2*root+2))) {
            
            if (k>0) 
                k--;
            else if (k==0) {
                return tree[root];
            }
        }
        return root;
    }
};

// Recursive Approach - Time Limit exceeded
class TreeAncestor {
public:
    vector<int> parents;
    vector<int> tree;
    TreeAncestor(int n, vector<int>& parent) {
        parents = parent;
        for(int i=0;i<n;i++) {
            tree.push_back(i);
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (k==0) return node;
        int parent = parents[node];
        if (parent<0) return -1;
        return getKthAncestor(parent, k-1);
    }
};


// Recursive + Memoization - Adress error
class TreeAncestor {
public:
    vector<int> parents;
    vector<int> tree;
    vector<vector<int>> record;
    TreeAncestor(int n, vector<int>& parent) {
        parents = parent;
        for(int i=0;i<n;i++) {
            tree.push_back(i);
        }
        record = vector<vector<int>> (n, vector<int>(n, -2));
    }
    
    int getKthAncestor(int node, int k) {
        if (record[node][k] != -2) return record[node][k];
        if (k==0) return node;
        int parent = parents[node];
        if (parent<0) return -1;
        record[node][k] = getKthAncestor(parent, k-1);
        return record[node][k];
    }
};


/* Discussion - 
Jump array is the logarithmic data structure. For each node, it 
stores 1st, 2nd, 4th, 8th and so on ancestors
First, we convert the input to some tree structure. Then, we 
traverse the tree, passing the whole path to from the current node 
to the root. Then, we add logarithmic ancestors to the jump array 
of the node i
For the query, we find the furtherest jump we can make, and then 
maximum possible recursive jumps until we reach our destination
Note that we store levels for each node, so we can immediatelly 
tell if k is too big.
*/

class TreeAncestor {
public:
    vector<vector<int>> jumps;
    vector<int> lvl;
    void traverse(vector<int>& path, vector<vector<int>> &tree, int i, int l) {
        lvl[i] = l;
        auto p = 1;
        while (p <= path.size()) {
            jumps[i].push_back(path[path.size() - p]);
            p <<= 1;
        }
        path.push_back(i);
        for (auto ch : tree[i]) {
            traverse(path, tree, ch, l + 1);
        }
        path.pop_back();
    }
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> tree(n);
        jumps = vector<vector<int>>(n);
        lvl = vector<int>(n);
        for (auto i = 1; i < n; ++i)
            tree[parent[i]].push_back(i);
        traverse(vector<int>() = {}, tree, 0, 0);
    }
    int getKthAncestor(int node, int k) {
        if (k == 0)
            return node;
        if (lvl[node] < k)
            return -1;
        auto p = 1, pos = 0;
        while ((p << 1) <= k) {
            p <<= 1;
            ++pos;
        }
        return getKthAncestor(jumps[node][pos], k - p);
    }
};