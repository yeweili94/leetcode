/*
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (51.38%)
 * Total Accepted:    106.7K
 * Total Submissions: 207.6K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        int pos = 0;
        while (pos < size) {
            while (nums[pos] != nums[nums[pos] - 1]){
                swap(nums[pos], nums[nums[pos] - 1]);
            }
            pos++;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] != i+1) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
