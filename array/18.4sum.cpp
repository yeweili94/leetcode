/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.14%)
 * Total Accepted:    173.2K
 * Total Submissions: 615.3K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    std::vector<std::vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if (size <= 3) {
            return ret;
        }
        for (int i = 0; i < size - 3; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1;
                for (; j < size - 2; j++) {
                    if (j == i + 1 || nums[j] != nums[j-1]) {
                        int low = j + 1, high = size - 1;
                        while (low < high) {
                            if (nums[low] + nums[high] + nums[i] + nums[j] > target) {
                                high--;
                            } else if (nums[low] + nums[high] + nums[i] + nums[j] < target) {
                                low++;
                            } else {
                                ret.push_back({nums[i], nums[j], nums[low], nums[high]});
                                high--;
                                while (low < high && nums[high] == nums[high+1]) {
                                    high--;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
