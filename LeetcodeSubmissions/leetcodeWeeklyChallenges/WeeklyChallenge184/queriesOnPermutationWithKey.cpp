/* 
Problem Statement - 

Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:
In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the 
permutation P (indexing from 0) and then move this at the beginning 
of the permutation P. Notice that the position of queries[i] in P is 
the result for queries[i].
Return an array containing the result for the given queries.

Example 1:

Input: queries = [3,1,2,1], m = 5
Output: [2,1,2,1] 
Explanation: The queries are processed as follow: 
For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
Therefore, the array containing the result is [2,1,2,1].  

Example 2:

Input: queries = [4,1,2,2], m = 4
Output: [3,1,2,0]

Example 3:

Input: queries = [7,5,5,8,3], m = 8
Output: [6,5,0,7,5]

Constraints:

* 1 <= m <= 10^3
* 1 <= queries.length <= m
* 1 <= queries[i] <= m
*/

// My solution
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int returnPos(vector<int>& arr, int len, int element) {
        for(int i=0;i<len;i++) {
            if (arr[i]==element)
                return i;
        }
        return -1;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans,P;
        for(int i=0;i<m;i++)
            P.push_back(i+1);
        P.push_back(0);
        for (int query:queries) {
            int idx = returnPos(P,m,query);
            int elem = P[idx];
            ans.push_back(idx);
            P.insert(P.begin(),P[idx]);
            for(auto it=P.begin()+1;it!=P.end();it++) {
                if (*it==elem){
                    P.erase(it);
                    break;
                }
            }
            P.push_back(0);
        }
        return ans;
    }
};

// Discussion - almost same

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> reff(m+1);
        for(int i=0; i<m; i++) {
            reff[i+1] = i;
        }
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            res[i] = reff[queries[i]];
            for(int j=1; j<=m; j++){
                if(reff[j] < res[i])
                    reff[j] += 1;
            }    
            reff[queries[i]] = 0;
        }
        return res;
    }
};