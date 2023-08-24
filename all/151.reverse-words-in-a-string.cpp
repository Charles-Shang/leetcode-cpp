/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (32.09%)
 * Likes:    5307
 * Dislikes: 4457
 * Total Accepted:    874.2K
 * Total Submissions: 2.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 *
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n)
     * Space: O(n)
     *
     * 58/58 cases passed (12 ms)
     * Your runtime beats 19.21 % of cpp submissions
     * Your memory usage beats 11.1 % of cpp submissions (34.4 MB)
     */
    // string reverseWords(string s) {
    //     string res = "";
    //     int i = 0, len = s.length();
    //     int not_end = 0;
    //     while (i < len) {
    //         while (s[i] == ' ') {
    //             i++;
    //             if (i == len) return res;
    //         }

    //         if (not_end) {
    //             res = " " + res;
    //         }

    //         string tmp = "";
    //         while (s[i] != ' ') {
    //             tmp += s[i++];
    //             if (i == len) return tmp + res;
    //         }

    //         not_end = 0;

    //         res = tmp + res;

    //         if (i < len) {
    //             not_end = 1;
    //         }
    //     }

    //     return res;
    // }

    /**
     * Time: O(n)
     * Space: O(1)
     *
     * 58/58 cases passed (5 ms)
     * Your runtime beats 55.99 % of cpp submissions
     * Your memory usage beats 93.74 % of cpp submissions (7.1 MB)
     */
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (slow != 0) s[slow++] = ' ';

                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end
