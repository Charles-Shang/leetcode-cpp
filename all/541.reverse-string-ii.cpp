/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (50.57%)
 * Likes:    1398
 * Dislikes: 2960
 * Total Accepted:    183.2K
 * Total Submissions: 362.2K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * Given a string s and an integer k, reverse the first k characters for every
 * 2k characters counting from the start of the string.
 *
 * If there are fewer than k characters left, reverse all of them. If there are
 * less than 2k but greater than or equal to k characters, then reverse the
 * first k characters and leave the other as original.
 *
 *
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n)
     * Space: O(1)
     *
     * 60/60 cases passed (3 ms)
     * Your runtime beats 84.19 % of cpp submissions
     * Your memory usage beats 25.04 % of cpp submissions (7.5 MB)
     */
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i += 2 * k) {
            if (i + k < len) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
// @lc code=end
