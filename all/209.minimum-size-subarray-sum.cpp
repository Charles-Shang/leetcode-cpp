/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.66%)
 * Likes:    8516
 * Dislikes: 236
 * Total Accepted:    647.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n)
     * Space: O(1)
     *
     * Time Spent: 10+15+15 min
     * 21/21 cases passed (25 ms)
     * Your runtime beats 98.25 % of cpp submissions
     * Your memory usage beats 24.4 % of cpp submissions (28.2 MB)
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int numsLen = nums.size();
        int min_length = numsLen + 1;
        int left = 0, right = 0;
        int cur_sum = nums[0];
        while (right < numsLen) {
            if (target > cur_sum) {
                right++;
                if (right == numsLen) {
                    break;
                }
                cur_sum += nums[right];
            } else {
                if (min_length > right - left + 1) {
                    min_length = right - left + 1;
                }

                cur_sum -= nums[left++];
            }
        }

        return min_length == numsLen + 1 ? 0 : min_length;
    }

    /**
     * Solution:
     * Time: O(n)
     * Space: O(1)
     *
     * 21/21 cases passed (20 ms)
     * Your runtime beats 99.66 % of cpp submissions
     * Your memory usage beats 24.4 % of cpp submissions (28.3 MB)
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int numsLen = nums.size();
        int min_length = numsLen + 1;
        int left = 0, right = 0;
        int cur_sum = 0;
        while (right < numsLen) {
            cur_sum += nums[right];
            while (cur_sum >= target) {
                if (min_length > right - left + 1) {
                    min_length = right - left + 1;
                }
                cur_sum -= nums[left++];
            }
            right++;
        }

        return min_length == numsLen + 1 ? 0 : min_length;
    }
};
// @lc code=end
