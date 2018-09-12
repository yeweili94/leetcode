/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (30.69%)
 * Total Accepted:    95.7K
 * Total Submissions: 312K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       int row = matrix.size();
       if (row == 0) return 0;
       int col = matrix[0].size();
       if (col == 0) return 0;
       int ret = 0;
       vector<int> h(col + 1, 0);
       for (int r = 0; r < row; r++) {
           for (int i = 0; i < col; i++) {
               if (matrix[r][i] == '1') {
                   h[i]++;
               } else {
                   h[i] = 0;
               }
           }
           stack<int> st;
           for (int j = 0; j <= col; j++) {
               while (!st.empty() && h[j] <= h[st.top()]) {
                   int top = st.top();
                   st.pop();
                   int w = st.empty() ? j : j - st.top() - 1;
                   ret = max(ret, w * (h[top]));
               }
               st.push(j);
           }
       }
       return ret;
    }
};
