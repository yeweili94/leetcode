/*
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (53.73%)
 * Total Accepted:    100K
 * Total Submissions: 186.1K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 * 
 * Example 1:
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 * 
 * 
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 * 
 * 
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int ret = 0;
        int local_len = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i-1]) {
                local_len++;
            } else if (nums[i] == 0){
                ret = max(ret, local_len);
                local_len = 1;
            } else {
                local_len = 1;
            }
        }
        if (nums[size - 1] == 1) {
            ret = max(ret, local_len);
        }
        return ret;
    }
};
