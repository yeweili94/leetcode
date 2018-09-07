/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (28.57%)
 * Total Accepted:    153.9K
 * Total Submissions: 538.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        int carry = 0;
        vector<int> ans(size1 + size2, 0);
        int pos = size1 + size2 - 1;
        for (int i = size1 - 1; i >= 0; i--) {
            for (int j = size2 - 1; j >= 0; j--) {
                pos = i + j + 1;
                int sum = carry + (num1[i] - '0') * (num2[j] - '0') + ans[pos];
                carry = sum / 10;
                ans[pos] = sum % 10;
            }
            pos--;
            while (carry && pos >= 0) {
                int sum = carry + ans[pos];
                ans[pos--] = sum % 10;
                carry = sum / 10;
            }
        }
        if (carry) {
            ans[0] = carry;
        }
        stringstream ss;
        int i = 0;
        while (ans[i] == 0) {
            i++;
        }
        for ( ; i < ans.size(); i++) {
            ss << ans[i];
        }
        string ret = ss.str();
        if (ret.empty()) {
            ret = "0";
        }
        return ret;
    }
};
