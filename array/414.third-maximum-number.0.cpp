/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.20%)
 * Total Accepted:    69.6K
 * Total Submissions: 246.9K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int size = nums.size();
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        for (int i = 0; i < size; i++) {
            if (nums[i] <= c || nums[i] == b || nums[i] == a) {
                continue;
            }
            c = nums[i];
            if (c > b) {
                swap(b, c);
            }
            if (b > a) {
                swap(a, b);
            }
        }
        return c == LLONG_MIN ? a : c;
    }
};
