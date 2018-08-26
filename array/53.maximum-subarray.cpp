/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (41.03%)
 * Total Accepted:    353.9K
 * Total Submissions: 862.5K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int ret = INT_MIN, local = 0;
        for (int i = 0; i < size; i++) {
            local += nums[i];
            ret = max(ret, local);
            if (local < 0) {
                local = 0;
            }
        }
        return ret;
    }
};
