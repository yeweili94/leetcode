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
    int largestRectangleArea(vector<int>& height) {
       height.push_back(0);
       int size = height.size();
       int ret = 0;
       stack<int> st;
       for (int i = 0; i < size; i++) {
           while (!st.empty() && height[i] <= height[st.top()]) {
               int top = st.top();
               st.pop();
               int w = st.empty() ? i : i - st.top() - 1;
               ret = max(ret, w * height[top]);
           }
           st.push(i);
       }
       return ret;
    }
};
