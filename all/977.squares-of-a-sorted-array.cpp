/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.91%)
 * Likes:    7154
 * Dislikes: 179
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 *
 *
 *
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n)
     * Space: O(n)
     *
     * Time Spent: 9 min
     * 137/137 cases passed (11 ms)
     * Your runtime beats 99.92 % of cpp submissions
     * Your memory usage beats 65.53 % of cpp submissions (25.8 MB)
     */
    vector<int> sortedSquares(vector<int>& nums) {
        int numLen = nums.size();
        vector<int> squares(numLen, 0);
        int left = 0, right = numLen - 1;
        int ptr = numLen - 1;
        while (ptr >= 0) {
            int absLeft = abs(nums[left]), absRight = abs(nums[right]);
            if (absLeft < absRight) {
                squares[ptr] = absRight * absRight;
                right--;
            } else {
                squares[ptr] = absLeft * absLeft;
                left++;
            }
            ptr--;
        }
        return squares;
    }
};
// @lc code=end