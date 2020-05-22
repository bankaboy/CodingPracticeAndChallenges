/*(This problem is an interactive problem.)
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in 
non-decreasing order.
Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. 
If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [m, n], which means the matrix is m * n.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions 
that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not 
have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */


/*
1. Perform binary search of each row, if you find 1 in a row, go left.
   Keep updating the lowest column number as answer.
   Complexity is O(H*log(W)) where H and W are height and width.
*/
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> shape = binaryMatrix.dimensions();
        int H=shape[0], W=shape[1];
        int answer = W;
        for (int row = 0;row<H;row++) {
            int low = 0, high = W-1;
            while(low<=high) {
                int mid = low + (high-low)/2;
                if (binaryMatrix.get(row,mid)==1) {
                    answer = min(answer,mid);
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
        }
        if (answer==W) return -1;
        return answer;
    }
};


/* 
  2. Can further optimize the above approach.
     Randomly access any row (done by storing row numbers is vector<int> order and random shuffle).
     Do not check columns after latest updated answer as we want least column number with 1.
     If element is 0 at latest answer then no use of checking the row(continue).
     If element is 1 at latest answer then there maybe 1 before that position as well
     (binary search from 0 to that position).
*/
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> shape = binaryMatrix.dimensions();
        int H=shape[0], W=shape[1];
        int answer = W;
        vector<int> order;
        for(int i=0;i<H;i++) {
            order.push_back(i);
        }
        random_shuffle(order.begin(),order.end());
        for (int row:order) {
            if (answer==0) {
                break;
            }         
            int low = 0, high = answer-1;
            if (binaryMatrix.get(row,high)==0) {
                continue;
            }
            while(low<=high) {
                int mid = low + (high-low)/2;
                if (binaryMatrix.get(row,mid)==1) {
                    answer = min(answer,mid);
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
        }
        if (answer==W) return -1;
        return answer;
    }
};

