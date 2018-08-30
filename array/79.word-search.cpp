/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.78%)
 * Total Accepted:    200.3K
 * Total Submissions: 695.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int size = word.size();
       if (size <= 0) {
           return false;
       }
       int row = board.size();
       if (row <= 0) return false;
       int col = board[0].size();
       if (col <= 0) return false;
       for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++) {
               if (helper(board, word, 0, i, j)) {
                   return true;
               }
           }
       }
       return false;
    }
    
    bool helper(vector<vector<char>>& board, 
                const string& word, int pos, int row, int col) {
        if (pos >= word.size()) {
            return true;
        }
        if (row < 0 || col < 0
                    || row >= board.size() 
                    || col >= board[0].size()
                    || board[row][col] != word[pos]) {
            return false;
        }
        board[row][col] = '*';
        bool ret = helper(board, word, pos + 1, row, col - 1)
                || helper(board, word, pos + 1, row, col + 1)
                || helper(board, word, pos + 1, row - 1, col)
                || helper(board, word, pos + 1, row + 1, col);
        board[row][col] = word[pos];
        return ret;
    }
};
