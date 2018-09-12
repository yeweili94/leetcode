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
       stack<int> st;
       int ret = 0;
       for (int i = 0; i < size; i++) {
           while (!st.empty() && height[st.top()] < height[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int w = i - st.top() - 1;
                ret += w * (min(height[i], height[st.top()]) - height[top]);
           }
           st.push(i);
       }
       return ret;
    }
};
