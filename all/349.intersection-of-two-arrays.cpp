/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (70.52%)
 * Likes:    4134
 * Dislikes: 2065
 * Total Accepted:    793.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
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
     * 55/55 cases passed (4 ms)
     * Your runtime beats 75.16 % of cpp submissions
     * Your memory usage beats 22.02 % of cpp submissions (10.5 MB)
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int n1 : nums1) {
            m[n1]++;
        }

        for (int n2 : nums2) {
            if (m[n2]) {
                result.push_back(n2);
                m[n2] = 0;
            }
        }

        return result;
    }
};
// @lc code=end
