/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (60.76%)
 * Likes:    8874
 * Dislikes: 348
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
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
     *
     * Time: O(n)
     * Space: O(1)
     *
     * Time Spent: 11 min
     * 55/55 cases passed (2 ms)
     * Your runtime beats 53.71 % of cpp submissions
     * Your memory usage beats 72.73 % of cpp submissions (7.5 MB)
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while (cur->next && cur->next->next) {
            ListNode* rest = cur->next->next->next;
            ListNode* first = cur->next;
            ListNode* second = cur->next->next;
            cur->next = second;
            second->next = first;
            first->next = rest;
            cur = first;
        }
        return dummyHead->next;
    }
};
// @lc code=end
