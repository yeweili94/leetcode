/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (48.53%)
 * Total Accepted:    98.4K
 * Total Submissions: 202.7K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(ret, temp, n, k, 1);
        return ret;
    }

    void helper(vector<vector<int>>& ret, vector<int> &tmp, int n, int k, int start) {
        if (start > 10) {
            return;
        }
        if (n == 0 && tmp.size() == k) {
            ret.push_back(tmp);
            return;
        }
        for (int i = start; i <= 9; i++) {
            tmp.push_back(i);
            helper(ret, tmp, n - i, k, i + 1);
            tmp.pop_back();
        }
    }
};
