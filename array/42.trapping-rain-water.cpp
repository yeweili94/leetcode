class Solution {
public:
    int trap(vector<int>& nums) {
        int size = nums.size();
        int ret = 0;
        for (int i = 1; i < size; i++) {
            int max_left = 0, max_right = 0;
            int j = i;
            while (j >= 0) {
                max_left = max(max_left, nums[j]);
                j--;
            }
            j = i;
            while (j < size) {
                max_right = max(max_right, nums[j]);
                j++;
            }
            ret += min(max_left, max_right) - nums[i];
        }
        return ret;
    }
};
