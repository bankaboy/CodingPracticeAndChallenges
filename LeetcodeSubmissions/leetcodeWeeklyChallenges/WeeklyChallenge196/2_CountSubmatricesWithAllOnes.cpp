/*
Given a rows * columns matrix mat of ones and zeros, return how 
many submatrices have all ones.

Example 1:
Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Example 2:
Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.

Example 3:
Input: mat = [[1,1,1,1,1,1]]
Output: 21

Example 4:
Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
Output: 5

Constraints:

1 <= rows <= 150
1 <= columns <= 150
0 <= mat[i][j] <= 1
*/

#include<bits/stdc++.h>
using namespace std;

// My solution - https://www.geeksforgeeks.org/number-of-submatrices-with-all-1s/
// Modified from square matrices to general case
class Solution {
public:
    void findPrefixCount(vector<vector<int>>& p_arr, vector<vector<int>>& arr, int n, int m) { 
        for (int i = 0; i < n; i++) { 
            for (int j = m - 1; j >= 0; j--) { 
              if (!arr[i][j]) 
                continue; 
  
                if (j != m - 1) 
                    p_arr[i][j] += p_arr[i][j + 1]; 
  
                p_arr[i][j] += (int)arr[i][j]; 
            } 
        } 
    } 
  
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> p_arr (n,vector<int>(m,0));
        findPrefixCount(p_arr, mat, n, m);
        int ans = 0;
        
        for (int j=0;j<m;j++) {
            int i = n-1;
            stack<pair<int,int>> q;
            int to_sum = 0;
            while(i>=0) {
                int c = 0;
                while (q.size() != 0 and q.top().first > p_arr[i][j]) { 
  
                    to_sum -= (q.top().second + 1)*(q.top().first - p_arr[i][j]); 
                      c += q.top().second + 1; 
                    q.pop(); 
                } 
  
                to_sum += p_arr[i][j]; 
  
                ans += to_sum; 
  
                q.push({ p_arr[i][j], c }); 
  
                i--; 
            } 
        } 
        return ans; 
    }
};

//Discussion 
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0) return 0;
        int cnt = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        for(int i = 0; i < m; ++i) {
            int cnt_1d = count_array(mat[i]);
            cnt += cnt_1d;
        
            //reset height
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) height[j] = 0;
            }

            //calculate # of added submatrix for row[i]
            int cnt_added = count_bar(height);
            cnt += cnt_added;

            //update height for next round 
            vector<int> height_nxt(n, 0);
            for(int j = 0; j < n; ++j) {
                if(mat[i][j]) height_nxt[j] = height[j] + mat[i][j];
            }
            swap(height, height_nxt);
        }
        return cnt;
    }
    int count_array(vector<int> arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] == 1) arr[i] = i == 0 ? arr[i] : arr[i-1] + arr[i];
            cnt += arr[i];
        }
        return cnt;
    }
    
    int count_bar(const vector<int> &height) {
        stack<pair<int, int>> stk; // pair: <index, # of rectangles> 
        stk.push({-1,0});
        int cnt = 0;
        for(int i = 0; i <= height.size(); ++i) {
            while(!stk.empty() && stk.top().first != -1 && (i == height.size() || height[stk.top().first] > height[i])) {
                int idx = stk.top().first;
                int rect_cnt = stk.top().second;
                stk.pop();
                cnt += (idx - stk.top().first) * height[idx] * rect_cnt;
                if(!stk.empty()) stk.top().second += rect_cnt;
            }   
            if(i < height.size()) stk.push(make_pair(i, 1));
        }
        return cnt;
    }
};