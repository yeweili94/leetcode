/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (41.74%)
 * Total Accepted:    190.7K
 * Total Submissions: 456.5K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows <= 0) {
            return ret;
        }
        ret.push_back(vector<int>(1,1));
        for (int i = 2; i <= numRows; i++) {
            const vector<int>& pre = ret.back();
            vector<int> temp;
            temp.push_back(pre[0]);
            for (int j = 1; j < pre.size(); j++) {
                temp.push_back(pre[j-1] + pre[j]);
            }
            temp.push_back(pre.back());
            ret.push_back(temp);
        }
        return ret;
    }
};
