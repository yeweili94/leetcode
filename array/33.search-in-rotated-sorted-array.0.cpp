/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.04%)
 * Total Accepted:    289.4K
 * Total Submissions: 903.2K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) { return -1; }
        int low = 0, high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (target > nums[high]) {
                if ( nums[mid] > target || (nums[mid] < target && nums[mid] < nums[high])) {
                    high = mid - 1;
                } else if (nums[mid] == target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] > nums[high]) {
                    low = mid + 1;
                } else if (nums[mid] > target) {
                    high = mid - 1;
                } else if (nums[mid] == target){
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (nums[low] == target) {
            return low;
        } else {
            return -1;
        }
    }
};
