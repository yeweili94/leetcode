class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return true;
        }
        queue<int> queue;
        queue.push(0);
        while (!queue.empty()) {
            int start = queue.front();
            int max_jump = 0;
            int num = queue.size();
            for (int i = 0; i < num; i++) {
                int tmp = queue.front();
                queue.pop();
                if (nums[tmp] + tmp > max_jump) {
                    max_jump = tmp + nums[tmp];
                }
            }
            if (max_jump >= size - 1) {
                return true;
            }
            for (int i = start + num; i <= max_jump; i++) {
                queue.push(i);
            }
        }
        return false;
    }
};
