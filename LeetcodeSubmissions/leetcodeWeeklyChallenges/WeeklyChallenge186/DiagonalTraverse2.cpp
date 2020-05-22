/* Diagonal Traverse 2

Given a list of lists of integers, nums, return all elements of 
nums in diagonal order as shown in the below images.

Example 1:
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

Example 2:
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

Example 3:
Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]

Example 4:
Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]
 
Constraints:
1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// My solution - 
/*pad the 2d array to make it uniform and push_back
 only the non zero numbers - time limit exceeded*/
class Solution {
    int minu(int a, int b) { return (a < b)? a: b; } 
    int min(int a, int b, int c) { return minu(minu(a, b), c);}
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> traversal;
        int row = nums.size(), col = nums[0].size();
        for (int i=0;i<row;i++) {
            if (nums[i].size()>col)
                col = nums[i].size();
        }
        for (int i=0;i<row;i++) {
            if (nums[i].size()<col) {
                int limit = col-nums[i].size()+1;
                for (int j=0;j<limit;j++)
                    nums[i].push_back(0);
            }
        }
        for (int line=1; line<=(row+col-1); line++) {
            int start_col = max(0,line-row);
            int count = min(line, (col-start_col), row);
            for (int j=0; j<count; j++) 
                if (nums[minu(row, line)-j-1][start_col+j]!=0)
                    traversal.push_back(nums[minu(row, line)-j-1][start_col+j]);
        }
        return traversal;        
    }
};

// Discussion

class Solution {
    int minu(int a, int b) { return (a < b)? a: b; } 
    int min(int a, int b, int c) { return minu(minu(a, b), c);}
public:
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> answer;
        unordered_map<int, vector<int>> m;
        int maxKey = 0; // maximum key inserted into the map i.e. max value of i+j indices.
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums[i].size(); j++) {
                m[i+j].push_back(nums[i][j]); // insert nums[i][j] in bucket (i+j).
                maxKey = max(maxKey, i+j); // 
            }
        }
        for (int i=0; i<= maxKey; i++) { // Each diagonal starting with sum 0 to sum maxKey.
            for (auto x = m[i].rbegin(); x != m[i].rend(); x++) { // print in reverse order.
                answer.push_back(*x); 
            }
        }
        
        return answer;
    }

};

/*
Key idea here is that in a 2D matrix elements in the same diagonal
have same sum of their indices.

So if we have all elements with same sum of their indices together,
then it’s just a matter of printing those elements in order.

Hence, the algorithm is -

Insert all elements into an appropriate bucket i.e. nums[i][j] in 
(i+j)th bucket.
For each bucket starting from 0 to max, print all elements in the 
bucket.
Note: Here, diagonals are from bottom to top, but we traversed the 
input matrix from first row to last row. Hence we need to print the 
elements in reverse order.
*/