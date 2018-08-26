#include <iostream>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return true;
        queue<int> queue;
        queue.push(0);
        int max_jump = 0;
        vector<bool> used(size, false);
        used[0] = true;
        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                int tmp = queue.front();
                queue.pop();
                if (tmp >= size - 1) {
                    return true;
                }
                if (nums[tmp] + tmp > max_jump) {
                    max_jump = tmp + nums[tmp];
                    if (max_jump >= size - 1) {
                        return true;
                    }
                    for (int j = tmp + 1; j <= max_jump; j++) {
                        if (!used[j]) {
                            queue.push(j);
                            used[j] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
} ;
