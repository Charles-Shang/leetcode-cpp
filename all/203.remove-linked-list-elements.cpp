/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (45.20%)
 * Likes:    6584
 * Dislikes: 195
 * Total Accepted:    863.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Given the head of a linked list and an integer val, remove all the nodes of
 * the linked list that has Node.val == val, and return the new head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [], val = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 10^4].
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    /**
     * Time: O(n)
     * Space: O(1)
     *
     * Time Spent: 7 min
     * 66/66 cases passed (22 ms)
     * Your runtime beats 68.39 % of cpp submissions
     * Your memory usage beats 35.7 % of cpp submissions (15 MB)
     */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode();
        ListNode* newHead = pre;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val != val) {
                pre->next = cur;
                pre = pre->next;
            }
        }

        if (pre != nullptr) {
            pre->next = nullptr;
        }

        return newHead->next;
    }
};
// @lc code=end
