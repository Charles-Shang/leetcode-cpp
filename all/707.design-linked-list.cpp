/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (27.54%)
 * Likes:    1962
 * Dislikes: 1365
 * Total Accepted:    239.3K
 * Total Submissions: 868.9K
 * Testcase Example:
 '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n'
 +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your implementation of the linked list. You can choose to use a
 * singly or doubly linked list.
 * A node in a singly linked list should have two attributes: val and next. val
 * is the value of the current node, and next is a pointer/reference to the
 * next node.
 * If you want to use the doubly linked list, you will need one more attribute
 * prev to indicate the previous node in the linked list. Assume all nodes in
 * the linked list are 0-indexed.
 *
 * Implement the MyLinkedList class:
 *
 *
 * MyLinkedList() Initializes the MyLinkedList object.
 * int get(int index) Get the value of the index^th node in the linked list. If
 * the index is invalid, return -1.
 * void addAtHead(int val) Add a node of value val before the first element of
 * the linked list. After the insertion, the new node will be the first node of
 * the linked list.
 * void addAtTail(int val) Append a node of value val as the last element of
 * the linked list.
 * void addAtIndex(int index, int val) Add a node of value val before the
 * index^th node in the linked list. If index equals the length of the linked
 * list, the node will be appended to the end of the linked list. If index is
 * greater than the length, the node will not be inserted.
 * void deleteAtIndex(int index) Delete the index^th node in the linked list,
 * if the index is valid.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * Output
 * [null, null, null, null, 2, null, 3]
 *
 * Explanation
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
 * myLinkedList.get(1);              // return 2
 * myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
 * myLinkedList.get(1);              // return 3
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= index, val <= 1000
 * Please do not use the built-in LinkedList library.
 * At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and
 * deleteAtIndex.
 *
 *
 */

// @lc code=start
class MyLinkedList {
    /**
     *
     * Time Spent: 30 min (multiple submissions)
     * 65/65 cases passed (23 ms)
     * Your runtime beats 99.69 % of cpp submissions
     * Your memory usage beats 45.38 % of cpp submissions (19.7 MB)
     */
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* head;
    int size;

   public:
    MyLinkedList() : head(nullptr), size(0) {}

    int get(int index) {
        if (index < 0 || index + 1 > size) {
            return -1;
        }

        ListNode* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }

        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val, head);
        head = newHead;
        size++;
    }

    void addAtTail(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            size++;
            return;
        }

        ListNode* cur = head;
        for (int i = 0; i < size - 1; i++) {
            cur = cur->next;
        }

        cur->next = new ListNode(val, nullptr);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else if (index < size) {
            ListNode* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            cur->next = new ListNode(val, cur->next);
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index + 1 > size) {
            return;
        }

        ListNode* cur = head;

        if (index == 0) {
            head = head->next;
            size--;
            return;
        }

        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
