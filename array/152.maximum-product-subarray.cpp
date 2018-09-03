/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (27.34%)
 * Total Accepted:    157.1K
 * Total Submissions: 574.4K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) {
            return 0;
        }
        int local_min = nums[0], local_max = nums[0];
        int ret = nums[0];
        for (int i = 1; i < size; i++) {
            int tmp_max = local_max, tmp_min = local_min;
            local_min = min(nums[i], min(tmp_min*nums[i], tmp_max*nums[i]));
            local_max = max(nums[i], max(tmp_max*nums[i], tmp_min*nums[i]));
            ret = max(ret, local_max);
        }
        return ret;
    }
};
