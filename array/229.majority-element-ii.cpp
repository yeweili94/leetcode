/*
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (30.02%)
 * Total Accepted:    79.2K
 * Total Submissions: 263.6K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if (size <= 0) {
            return ret;
        }
        int cnt1 = 1, cnt2 = 1;
        int pos = 1, target1 = nums[0];
        while (pos < size && nums[pos] == nums[pos-1]) {
            cnt1++;
            pos++;
        }
        if (pos == size) {
            ret.push_back(target1);
            return ret;
        }
        int target2 = nums[pos];
        for (pos = pos + 1; pos < size; pos++) {
            if (nums[pos] == target1) {
                cnt1++;
            } else if (nums[pos] == target2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                target1 = nums[pos];
            } else if (cnt2 == 0) {
                cnt2 = 1;
                target2 = nums[pos];
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == target1) {
                cnt1++;
            }else if (nums[i] == target2) {
                cnt2++;
            }
        }
        if (cnt1 > size / 3) {
            ret.push_back(target1);
        } 
        if (cnt2 > size / 3) {
            ret.push_back(target2);
        }
        return ret;
    }
};
