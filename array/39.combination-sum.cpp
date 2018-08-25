/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (43.14%)
 * Total Accepted:    244.5K
 * Total Submissions: 566.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        vector<vector<int>> ret;
        if (size <= 0) {
            return ret;
        }
        vector<int> temp;
        helper(ret, candidates, temp, 0, target);
        return ret;
    }

    void helper(vector<vector<int>>& ret, const vector<int>& candidates, 
                vector<int>& temp, int pos, int target) {
        if (target == 0) {
            ret.push_back(temp);
            return;
        }
        if (target < 0 || pos == candidates.size()) {
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            helper(ret, candidates, temp, i, target - candidates[i]);
            temp.pop_back();
        }
    }
 };
