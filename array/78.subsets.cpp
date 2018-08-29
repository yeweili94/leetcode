/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (47.13%)
 * Total Accepted:    266.9K
 * Total Submissions: 566.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ret;
        if (size <= 0) {
            return ret;
        }
        vector<int> temp;
        helper(ret, temp, nums, 0);
        return ret;
    }

    void helper(vector<vector<int>>& ret, vector<int>& temp, const vector<int> &nums, int start) {
        if (start > nums.size()) {
            return;
        }
        ret.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(ret, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};
