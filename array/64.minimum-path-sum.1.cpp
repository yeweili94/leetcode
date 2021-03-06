/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (42.50%)
 * Total Accepted:    168.8K
 * Total Submissions: 397K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int col = grid[0].size();
        vector<int> dp(col, grid[0][0]);
        for (int i = 1; i < col; i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for (int i = 1; i < row; i++) {
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < col; j++) {
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp[col-1];
    }
};
