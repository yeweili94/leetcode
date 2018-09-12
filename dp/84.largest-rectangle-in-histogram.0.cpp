/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (28.59%)
 * Total Accepted:    133.1K
 * Total Submissions: 465.6K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> st;
        vector<int> left(size, 0);
        vector<int> right(size, size - 1);
        for (int i = 0; i < size; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i - 1;
                st.pop();
            }
            st.push(i);
        }
        stack<int> st1;
        swap(st, st1);
        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i + 1;
                st.pop();
            }
            st.push(i);
        }
        int ret = 0;
        for (int i = 0; i < size; i++) {
            ret = max(ret, heights[i] * (right[i] - left[i] + 1));
        }
        return ret;
    }
};
