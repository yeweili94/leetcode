/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.02%)
 * Total Accepted:    289.3K
 * Total Submissions: 722.8K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int low = 0, high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (target > nums[low]) {
            return low + 1;
        } else {
            return low;
        }
    }
};
