class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return true;
        }
        int left = 0, right = 0;
        while (left < size && right < size) {
            int max_jump = 0;
            if (left >= size - 1 || right >= size - 1) {
                return true;
            }
            for (int i = left; i <= right; i++) {
                if (max_jump < i + nums[i]) {
                    max_jump= i + nums[i];
                }
            }
            if (max_jump <= right) {
                return false;
            }
            left = right + 1;
            right = max_jump;
        }
        return true;
    }
};
