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
        if (col == 0) {
            return 0;
        }
        vector<int> ans;
        vector<int> temp;
        helper(ans, temp, grid, 0, 0);
        int ret = INT_MAX;
        for (int i = 0; i < ans.size(); i++) {
            ret = min(ret, ans[i]);
        }
        return ret;
    }

    void helper(vector<int>& ans, vector<int>& temp, const vector<vector<int>>& grid, int row, int col) {
        int r = grid.size(), c = grid[0].size();
        if (row < 0 || row >= r || col < 0 || col >= c) {
            return;
        }
        if (row == r - 1 && col == c - 1) {
            temp.push_back(grid[row][col]);
            ans.push_back(accumulate(temp.begin(), temp.end(), 0));
            temp.pop_back();
            return;
        }
        temp.push_back(grid[row][col]);
        helper(ans, temp, grid, row + 1, col);
        helper(ans, temp, grid, row, col + 1);
        temp.pop_back();
    }
};
