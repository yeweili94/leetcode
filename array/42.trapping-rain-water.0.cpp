class Solution {
public:
    int trap(vector<int>& nums) {
        int size = nums.size();
        vector<int> max_left(size, 0);
        vector<int> max_right(size, 0);
        int max_num = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] > max_num) {
                max_num = nums[i];
            }
            max_left[i] = max_num;
        }
        max_num = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (nums[i] > max_num) {
                max_num = nums[i];
            }
            max_right[i] = max_num;
        }
        int ret = 0;
        for (int i = 1; i < size; i++) {
            ret += min(max_left[i], max_right[i]) - nums[i];
        }
        return ret;
    }
};
