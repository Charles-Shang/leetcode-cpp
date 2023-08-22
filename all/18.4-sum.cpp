/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.25%)
 * Likes:    8433
 * Dislikes: 978
 * Total Accepted:    692.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n^3)
     * Space: O(1)
     *
     * 293/293 cases passed (80 ms)
     * Your runtime beats 55.89 % of cpp submissions
     * Your memory usage beats 94.34 % of cpp submissions (13.1 MB)
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] > target && nums[k] >= 0) {
                break;
            }

            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] >
                        target) {
                        right--;
                    } else if ((long)nums[k] + nums[i] + nums[left] +
                                   nums[right] <
                               target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i],
                                                     nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        while (right > left && nums[left] == nums[left + 1])
                            left++;

                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
