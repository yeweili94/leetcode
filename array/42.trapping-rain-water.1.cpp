class Solution {
public:
    int trap(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) { return 0; }
        int max_left = 0, max_right = 0;
        int left = 0, right = size - 1;
        int ret = 0;
        while (left < right) {
            if (nums[left] < nums[right]) {
                nums[left] > max_left ? (max_left = nums[left]) : ret += (max_left - nums[left]);
                left++;
            } else {
                nums[right] > max_right ? (max_right = nums[right]) : ret += (max_right - nums[right]);
                right--;
            }
        }
        return ret;
    }
};
