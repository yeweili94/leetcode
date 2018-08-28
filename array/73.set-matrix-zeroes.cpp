/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (37.40%)
 * Total Accepted:    156.2K
 * Total Submissions: 417.7K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row <= 0) {
            return;
        }
        int col = matrix[0].size();
        if (col <= 0) {
            return;
        }
        bool is_row = false, is_col = false;
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                is_col = true;
            }
        }
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                is_row = true;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (is_row) {
            for (int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        if (is_col) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
