/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (33.00%)
 * Total Accepted:    135K
 * Total Submissions: 408.9K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int ret = INT_MAX;
        int left = 0, right = 0;
        int sum = nums[0];
        while (left <= right && right < size) {
            if (sum < s) {
                right++;
                sum += nums[right];
            } else {
                ret = min(ret, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        ret = (ret == INT_MAX ? 0 : ret);
        return ret;
    }
};
