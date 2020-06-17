/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example:
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 
'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two 
cells are connected if they are adjacent cells connected horizontally or vertically.
*/

/* 
Algorithm - 
1. Find the 'O's in the boundary of the matrix and their neighbors.
2. Mark them with some special notation, since they will not be considered as they are not surrounded by 'X' in all
   directions.
3. Now go through the entire matrix and change all the rermaining 'O's to 'X', and the special characters back to 'O'.
*/

class Solution {
public:
    void bfsBoundary(vector<vector<char>>& board, int w, int l) {
        int width = board.size(), length = board[0].size();
        deque<pair<int, int>> q; // queue for BFS
        q.push_back(make_pair(w,l));
        board[w][l] = 'B'; // mark B to be later converted back to O, for border elements and neighbors
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop_front();
            pair<int, int> adjs[4] = {{cur.first-1, cur.second}, 
                                     {cur.first+1, cur.second}, 
                                     {cur.first, cur.second-1},
                                     {cur.first, cur.second+1}};
            for (int i = 0; i < 4; ++i) {
                int adjW = adjs[i].first;
                int adjL = adjs[i].second;
                if ((adjW >= 0) && (adjW < width) && (adjL >= 0)
                        && (adjL < length) 
                        && (board[adjW][adjL] == 'O')) {
                    q.push_back(make_pair(adjW, adjL));
                    board[adjW][adjL] = 'B';
                }
            }
        }        
    }
    
    void solve(vector<vector<char>>& board) {
        int width = board.size();
        if (width == 0) //Add this to prevent run-time error!
            return;
        int length = board[0].size();
        if  (length == 0) // Add this to prevent run-time error!
            return;
    
        // changing boundary clusters to B
        for (int i = 0; i < length; ++i) {
            // first row
            if (board[0][i] == 'O')
                bfsBoundary(board, 0, i);
            // last row
            if (board[width-1][i] == 'O')
                bfsBoundary(board, width-1, i);
        }

        for (int i = 0; i < width; ++i) {
            // first column
            if (board[i][0] == 'O')
                bfsBoundary(board, i, 0);
            // last column
            if (board[i][length-1] == 'O')
                bfsBoundary(board, i, length-1);
        }

        // change all O to X and B to O
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'B')
                    board[i][j] = 'O';
            }
        }
    }
};
