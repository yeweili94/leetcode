/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.54%)
 * Total Accepted:    227.8K
 * Total Submissions: 640.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int size1 = a.size(), size2 = b.size();
        int pos1 = size1 - 1, pos2 = size2 - 1;
        int carry = 0;
        vector<int> ret(max(size1, size2) + 1, 0);
        int pos = ret.size() - 1;
        while (carry || pos1 >= 0 || pos2 >= 0) {
            int sum = carry;
            if (pos1 >= 0) {
                sum += a[pos1] - '0';
                pos1--;
            }
            if (pos2 >= 0) {
                sum += b[pos2] - '0';
                pos2--;
            }
            ret[pos--] = sum % 2;
            carry = sum / 2;
        }
        int i = 0;
        while (i < ret.size() && ret[i] == 0) {
            i++;
        }
        stringstream ss;
        for (; i < ret.size(); i++) {
            ss << ret[i];
        }
        std::string ans = ss.str();
        if (ans.empty()) {
            ans = "0";
        }
        return ans;
    }
};
