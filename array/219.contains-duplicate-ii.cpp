/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (33.47%)
 * Total Accepted:    159.2K
 * Total Submissions: 475.4K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_set<int> set;
        int left = 0, right = 0;
        while (right <= k && right < size) {
            if (set.find(nums[right]) != set.end()) {
                return true;
            }
            set.insert(nums[right++]);
        }
        while (right < size) {
            set.erase(nums[left++]);
            if (set.find(nums[right]) != set.end()) {
                return true;
            }
            set.insert(nums[right++]);
        }
        return false;
    }
};
