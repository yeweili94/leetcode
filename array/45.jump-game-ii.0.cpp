class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return 0;
        }
        queue<int> queue;
        queue.push(0);
        int step = 0;
        vector<bool> used(size, false);
        used[0] = true;
        int max_jump = 0;
        while (!queue.empty()) {
            int num = queue.size();
            for (int i = 0; i < num; i++) {
                int j = queue.front();
                queue.pop();
                if (j + nums[j] > max_jump) {
                    max_jump = j + nums[j];
                    if (max_jump >= size - 1) {
                        return step + 1;
                    }
                    for (int s = j + 1; s <= max_jump; s++) {
                        if (!used[s]) {
                            queue.push(s);
                            used[s] = true;
                        }
                    }
                }
            }
            step++;
        }
        return step;
    }
};
