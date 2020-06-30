/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:
Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
 
Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

// Try 1 - Dfs in matrix - TLE
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        for (string word: words) {
            if (exist(board, word)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0;i<board.size(); i++) {
            for (int j=0;j<board[0].size(); j++) {
                vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(),false));
                if (board[i][j] == word[0] && dfsExist(board, word, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool dfsExist(vector<vector<char>>& board, string word, int i, int j, int position, vector<vector<bool>>& visited) {
        if (position == word.size())
            return true;
        if (i>=0 && i<board.size() && j>=0 && j<board[0].size() && !visited[i][j] && board[i][j]==word[position]) {
            visited[i][j] = true;
            bool result = (dfsExist(board, word, i, j + 1, position + 1, visited) ||
                    dfsExist(board, word, i + 1, j, position + 1, visited) ||
                    dfsExist(board, word, i - 1, j, position + 1, visited) ||
                    dfsExist(board, word, i, j - 1, position + 1, visited));
            visited[i][j] = false; // back track
            return result;
        } else {
            return false;
        }
    }
};

// Trie 
class Trie{
public:
    Trie* children[26];
    bool endOfWord;
    Trie():endOfWord(false){
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
    ~Trie(){
        for(int i = 0; i < 26; ++i)
            if(children[i]) delete children[i];
    }
    
    void insert(string word){
        Trie* curr = this;
        for(char c: word){
            if(!curr->children[c-'a']) curr->children[c - 'a'] = new Trie();
            curr = curr->children[c-'a'];
        }
        curr->endOfWord = true;
    }
};

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, Trie* trie, unordered_set<string>& result, string s){
        char c = board[i][j];
        if(c == '$') return;
        board[i][j] = '$';
        Trie* t = trie->children[c - 'a'];
        if(t){
            string ss = s + c;
            if(t->endOfWord) result.insert(ss);
            if(i < board.size()-1) dfs(board, i+1, j, t, result, ss);
            if(i > 0) dfs(board, i-1, j, t, result, ss);
            if(j < board[0].size()-1) dfs(board, i, j+1, t, result, ss);
            if(j > 0) dfs(board, i, j-1, t, result, ss);
        }
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0) return {};
        Trie trie;
        for(string w: words){
            trie.insert(w);
        }
        
        unordered_set<string> result_s;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                dfs(board, i, j, &trie, result_s, "");
            }
        }
        vector<string> result(result_s.begin(), result_s.end());
        return result;
    }
};
