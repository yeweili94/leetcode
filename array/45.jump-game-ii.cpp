class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return 0;
        }
        int left = 0, right = 0;
        int step = 0;
        while (left < size - 1 && right < size - 1) {
            int max_jump = 0;
            for (int i = left; i <= right; i++) {
                if (i + nums[i] > max_jump) {
                    max_jump = i + nums[i];
                }
            }
            step++;
            if (max_jump >= size - 1) {
                return step;
            }
            left = right + 1;
            right = max_jump;
        }
        return step;
    }
};
