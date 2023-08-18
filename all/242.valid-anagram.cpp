/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (62.85%)
 * Likes:    7932
 * Dislikes: 253
 * Total Accepted:    1.9M
 * Total Submissions: 3M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n+m)
     * Space: O(1)
     *
     * Time Spent: 13 min
     * 42/42 cases passed (5 ms)
     * our runtime beats 84.32 % of cpp submissions
     * Your memory usage beats 15.4 % of cpp submissions (7.4 MB)
     */
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        for (char c : s) {
            m[c]++;
        }

        for (char c : t) {
            m[c]--;
        }

        for (auto i : m) {
            if (i.second) {
                return false;
            }
        }

        return true;
    }

    /**
     * Time: O(n+m)
     * Space: O(1)
     *
     * 42/42 cases passed (3 ms)
     * Your runtime beats 98.25 % of cpp submissions
     * Your memory usage beats 44.74 % of cpp submissions (7.4 MB)
     */
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
