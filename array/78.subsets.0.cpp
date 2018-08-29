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
       vector<vector<int>> ret(1, vector<int>());
       int size = nums.size();
       if (size <= 0) {
           return ret;
       }
       for (int i = 0; i < size; i++) {
           int n = ret.size();
           for (int j = 0; j < n; j++) {
               ret.push_back(ret[j]);
               ret.back().push_back(nums[i]);
           }
       }
       return ret;
    }
};
