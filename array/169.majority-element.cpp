/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (49.33%)
 * Total Accepted:    291.8K
 * Total Submissions: 591.6K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, target = nums[0];
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        for (int i = 1; i < size; i++) {
            if (nums[i] == target){
                cnt ++;
            } else {
                cnt --;
            }
            if (cnt < 0) {
                cnt = 1;
                target = nums[i];
            }
        }
        return target;
    }
};
