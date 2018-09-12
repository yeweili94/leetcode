/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (38.80%)
 * Total Accepted:    190.7K
 * Total Submissions: 491.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> left(size, 0);
        vector<int> right(size, size - 1);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            if (st.empty()) {
                st.push(i);
            } else {
                while (!st.empty() && height[st.top()] > height[i]) {
                    right[st.top()] = i - 1;
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty()) {
            right[st.top()] = size - 1;
            st.pop();
        }

        for (int i = size - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(i);
            } else {
                while (!st.empty() && height[st.top()] > height[i]) {
                    left[st.top()] = i + 1;
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty()) {
            right[st.top()] = 0;
            st.pop();
        }
        int ret = 0;
        for (int i = 0; i < size; i++) {
            ret += (min(height[left[i]], height[right[i]]) - height[i]);
            printf("%d\t%d", height[left[i]], height[right[i]]);
        }
        return ret;
    }
};
