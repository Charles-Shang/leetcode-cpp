/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (54.57%)
 * Likes:    7728
 * Dislikes: 965
 * Total Accepted:    1M
 * Total Submissions: 1.9M
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is happy.
 *
 * A happy number is a number defined by the following process:
 *
 *
 * Starting with any positive integer, replace the number by the sum of the
 * squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), or it
 * loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 *
 *
 * Return true if n is a happy number, and false if not.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n+m)
     * Space: O(1)
     *
     * 420/420 cases passed (5 ms)
     * Your runtime beats 19.62 % of cpp submissions
     * Your memory usage beats 7.48 % of cpp submissions (6.6 MB)
     */
    bool isHappy(int n) {
        unordered_map<int, int> m = {{n, 1}};
        int cur = n;
        while (1) {
            int sum = getSum(cur);
            if (sum == 1) {
                return true;
            } else if (m[sum]) {
                return false;
            }

            m[sum] = 1;
            cur = sum;
        }
    }

   private:
    int getSum(int n) {
        int sum = 0;
        for (int cur = n; cur; cur /= 10) {
            int digit = cur % 10;
            sum += digit * digit;
        }
        return sum;
    }
};
// @lc code=end
