class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }
        int low = 0;
        for (int i = 0; i < size; i++) {
            if (low < 2 || nums[i] > nums[low-2]) {
                nums[low++] = nums[i];
            }
        }
        return low;
    }
};
