/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (33.37%)
 * Total Accepted:    108.4K
 * Total Submissions: 324.8K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int size = nums.size();
        if (size <= 0) {
            return ret;
        }
        stringstream ss;
        int left = 0, right = 0;
        while (right < size) {
            while (right < size - 1 && nums[right] == nums[right+1] - 1) {
                right++;
            }
            if (left == right) {
                ss << nums[left];
            }
            else {
                ss << nums[left] << '-' << '>' << nums[right];
            }
           ret.push_back(ss.str());
           ss.str("");
           left = right + 1;
           right = left;
        }
        return ret;
    }
};
