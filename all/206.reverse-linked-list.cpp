/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.84%)
 * Likes:    16143
 * Dislikes: 272
 * Total Accepted:    2.8M
 * Total Submissions: 3.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
     * Time Spent: 5 min
     * 28/28 cases passed (4 ms)
     * Your runtime beats 72.15 % of cpp submissions
     * Your memory usage beats 58.67 % of cpp submissions (8.2 MB)
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        for (ListNode* cur = head; cur;) {
            ListNode* tmp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = tmp;
        }
        return newHead;
    }
};
// @lc code=end
