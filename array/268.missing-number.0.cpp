/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (45.99%)
 * Total Accepted:    199.7K
 * Total Submissions: 434.2K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 * 
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int ret = 0;
       int size = nums.size();
       for (int i = 0; i < size; i++) {
           ret = ret ^ i+1 ^ nums[i];
       }
       return ret;
    }
};
