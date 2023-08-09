/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 *
 * https://leetcode.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (55.21%)
 * Likes:    7618
 * Dislikes: 166
 * Total Accepted:    1.5M
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * Given an array of integers nums which is sorted in ascending order, and an
 * integer target, write a function to search target in nums. If target exists,
 * then return its index. Otherwise, return -1.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 < nums[i], target < 10^4
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
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
     */
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int left = 0, right = length - 1;

        while (left <= right) {
            // bit operator: int mid = left + (right - left >> 1)
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
/**
 * Time: 8 min
 * 47/47 cases passed (28 ms)
 * Your runtime beats 91.26 % of cpp submissions
 * Your memory usage beats 32.02 % of cpp submissions (27.5 MB)
 */