/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (52.25%)
 * Total Accepted:    335.7K
 * Total Submissions: 642.4K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return;
        }
        int low = 0, high = high;
        while (high < size) {
            if (nums[high] != 0) {
                nums[low++] = nums[high++];
            } else {
                high++;
            }
        }
        while (low < size) {
            nums[low++] = 0;
        }
    }
};
