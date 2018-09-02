/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (36.17%)
 * Total Accepted:    145.8K
 * Total Submissions: 402.6K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<int> dp(size, triangle[0][0]);
        vector<int> dp1(size, triangle[0][0]);
        for (int i = 1; i < size; i++) {
            dp1[0] = dp[0] + triangle[i][0];
            int j = 1;
            for ( ; j < i; j++) {
                dp1[j] = triangle[i][j] + min(dp[j], dp[j-1]);
            }
            dp1[j] = dp[j-1] + triangle[i][j];
            swap(dp, dp1);
        }
        int ret = INT_MAX;
        for (int i = 0; i < dp.size(); i++) {
            if (ret > dp[i]) {
                ret = dp[i];
            }
        }
        return ret;
    }
};
