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
        int n = pow(2, size);
        for (int i = 0; i < n; i++) {
            convert_digit_to_vec(nums, ret, i, size);
        }
        return ret;
    }

    void convert_digit_to_vec(const vector<int>& nums, vector<vector<int>>& ret, int digit, int size) {
        //int pos = size - 1;
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            if (digit >> i & 1 == 1) {
                temp.push_back(nums[i]);
            }
            /* digit >>= 1; */
        }
        ret.push_back(temp);
    }
};
