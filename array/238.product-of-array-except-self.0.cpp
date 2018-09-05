/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (51.44%)
 * Total Accepted:    174.5K
 * Total Submissions: 339.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size, 1);
        int right = 1;
        for (int i = 1; i < size; i++) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        for (int i = size - 2; i >= 0; i--) {
            right *= nums[i+1];
            ret[i] *= right;
        }
        return ret;
    }
};
