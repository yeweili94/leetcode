/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (42.60%)
 * Total Accepted:    110.1K
 * Total Submissions: 258.4K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            vector<vector<int>> tmp;
            return tmp;
        }
        vector<vector<int>> ret(n, vector<int>(n, -1));
        int dir_row[4] = {0, 1, 0, -1};
        int dir_col[4] = {1, 0, -1, 0};
        int step = 0;
        int r = 0, c = 0;
        for (int i = 0; i < n * n; i++) {
            ret[r][c] = i + 1;
            int r_tmp = r + dir_row[step];
            int c_tmp = c + dir_col[step];
            if (r_tmp < 0 || r_tmp >= n || c < 0 || c_tmp >= n || ret[r_tmp][c_tmp] != -1) {
                step = (step + 1) % 4;
                r = r + dir_row[step];
                c = c + dir_col[step];
            } else {
                r = r_tmp;
                c = c_tmp;
            }
        }
        return ret;
    }   
};
