/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (69.93%)
 * Likes:    5878
 * Dislikes: 238
 * Total Accepted:    510.1K
 * Total Submissions: 729.3K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /**
     * Time: O(n^2)
     * Space: O(n^2)
     *
     * Time Spent:20 min
     * 20/20 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 18.81 % of cpp submissions (6.8 MB)
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int row = 0, col = 0;
        int up_bound = 0, down_bound = n - 1, left_bound = 0,
            right_bound = n - 1;
        int counter = 1;
        int counter_bound = n * n;
        while (1) {
            while (col <= right_bound) {
                // cout << "(" << row << "," << col << ") " << counter << endl;
                matrix[row][col++] = counter++;
            }
            if (counter > counter_bound) {
                break;
            }
            col--;
            row++;
            up_bound++;
            while (row <= down_bound) {
                // cout << "(" << row << "," << col << ") " << counter << endl;
                matrix[row++][col] = counter++;
            }
            if (counter > counter_bound) {
                break;
            }
            row--;
            col--;
            right_bound--;
            while (col >= left_bound) {
                // cout << "(" << row << "," << col << ") " << counter << endl;
                matrix[row][col--] = counter++;
            }
            if (counter > counter_bound) {
                break;
            }
            row--;
            col++;
            down_bound--;
            while (row >= up_bound) {
                // cout << "(" << row << "," << col << ") " << counter << endl;
                matrix[row--][col] = counter++;
            }
            if (counter > counter_bound) {
                break;
            }
            row++;
            col++;
            left_bound++;
        }

        return matrix;
    }
};
// @lc code=end
