/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (58.03%)
 * Total Accepted:    69.7K
 * Total Submissions: 120K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        unordered_set<int> duplicat;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) == set.end()) {
                set.insert(nums[i]);
            }
            else {
                if (duplicat.find(nums[i]) == duplicat.end()) {
                    duplicat.insert(nums[i]);
                    ret.push_back(nums[i]);
                }
            }
        }
        return ret;
    }
};
