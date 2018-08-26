class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int good_position = size - 1;
        for (int i = good_position - 1; i >= 0; i--) {
            if (i + nums[i] >= good_position) {
                good_position = i;
            }
        }
        return good_position == 0;
    }
};
