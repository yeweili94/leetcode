/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    358.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        pair<int,int> index(0,0);
        string ret;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j) {
                    dp[j][i] = 1;
                } else if (s[i] == s[j]) {
                    if (i - j > 1 && dp[j+1][i-1] ) {
                        dp[j][i] = dp[j+1][i-1] + 2;
                    } else if (i - j == 1) {
                        dp[j][i] = 2;
                    }
                }
                if (dp[j][i] > ret.size()) {
                    ret = s.substr(j, i - j + 1);
                }
            }
        }
        return ret;
    }
};
