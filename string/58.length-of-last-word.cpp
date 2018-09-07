/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.09%)
 * Total Accepted:    210.7K
 * Total Submissions: 656.7K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int pos = size - 1;
        while (pos >= 0 && !isalpha(s[pos])) {
            pos--;
        }
        int ret = 0;
        while (isalpha(s[pos])) {
            ret++;
            pos--;
        }
        return ret;
    }
};
