/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (30.48%)
 * Total Accepted:    228.3K
 * Total Submissions: 748.9K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m == 0 || n == 0 || m < n) return "";
        vector<int> ans(3, 0);
        ans[0] = INT_MAX;
        int l = 0, r = 0;
        int formed = 0;
        unordered_map<char, int> dict;
        for (const auto& elem : t) dict[elem]++;
        unordered_map<char, int> form;
        while (r < m) {
            char c = s[r];
            form[c]++;
            if (dict.find(c) != dict.end() && form[c] == dict[c]) {
                formed++;
            }
            while (l <= r && formed == (int)dict.size()) {
                char elem = s[l];
                int len = r - l + 1;
                if (len < ans[0]) {
                    ans[0] = len;
                    ans[1] = l;
                    ans[2] = r;
                }
                form[elem]--;
                if (dict.find(elem) != dict.end() && form[elem] < dict[elem]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
    }
};
