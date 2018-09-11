/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.74%)
 * Total Accepted:    142.7K
 * Total Submissions: 600.9K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        vector<int> dp(size, 0);        
        int ret = 0;
        for (int i = 1; i < size; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = 2 + (i>=2?dp[i-2]:0);
                } else {
                    if ((i-1-dp[i-1] >= 0) && (s[i-1-dp[i-1]] == '(')) {
                        dp[i] = dp[i-1] + 2;
                        if (i-1-dp[i-1]-1 >= 0) {
                            dp[i] += dp[i-1-dp[i-1]-1];
                        }
                    }
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
