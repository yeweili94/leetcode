/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.06%)
 * Total Accepted:    531.5K
 * Total Submissions: 2M
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 0) return "";
        vector<vector<int>> dp(size, vector<int>(size, 0));
        int m = 0, n = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == i) {
                    dp[j][i] = 1;
                } else if (s[j] != s[i]) {
                    dp[j][i] = 0;
                } else {
                    if (i == j + 1) {
                        dp[j][i] = 2;
                    } else {
                        dp[j][i] = dp[j+1][i-1] ? dp[j+1][i-1] + 2 : 0;
                    }
                }
                if (dp[j][i] > n-m+1) {
                    m = j;
                    n = i;
                }
            }
        }
        return s.substr(m, n-m+1);
    }
};
