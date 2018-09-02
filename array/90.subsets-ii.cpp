/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (39.50%)
 * Total Accepted:    162.3K
 * Total Submissions: 410.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        int size = nums.size();
        if (size <= 0) {
            return ret;
        }
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(ret, nums, temp, 0);
        return ret;
    }

    void helper(vector<vector<int>>& ret, const vector<int>& nums, vector<int>& temp, int start) {
        if (start > nums.size()) {
            return;
        }
        ret.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1]) {
                continue;
            }
            temp.push_back(nums[i]);
            helper(ret, nums, temp, i + 1);
            temp.pop_back();
        }
    }
};
