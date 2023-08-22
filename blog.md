# Leetcode Tracking Blog

## Day 1

> 数组理论基础，704. 二分查找，27. 移除元素

* [X] 704 Binary Search (8 min)
  * 经典的二分查找，注意区间
* [X] 27 Remove Element (6 min)
  * 最先想到的就是交换，采用快慢指针

## Day 2

> 977.有序数组的平方 ，209.长度最小的子数组 ，59.螺旋矩阵II ，总结

* [X] 997 Squares of a Sorted Array (9 min)
  * 最直接想到的是：先全部平方，然后来一个排序。
  * 但由于题目中已经给出已知数组是non-descending order，于是想到两个指针左右对比，从两边到中间缩进。然后对于新创建的数组（用于存储结果），用一个指针从最右向左递进。
* [X] 209 Minimum Size Subarray Sum (10+15+15 min)
  * 双指针做滑动窗口
  * 做了三次才提交结果正确，第二次提交失败之后我才注意到题目中是要求 `target <= sum` 即可，我一直以为是 `target == sum`, 最初还想着这不应该是dp问题么，但之前自己坐过这个题目，知道是滑动窗口。
  * 回顾c哥的做法，发现确实比我的要简洁明了很多, 对于每一个右指针，假如当前的总和大于target，那么移动做指针向右，直到总和小于target
* [X] 59 Spiral Matrix II (17 min)
  * 搞清楚边界很重要，然后主要思路就是跟着绕一圈就可以了

### 数组专题总结

1. 最容易忽略的就是边界问题，在写题时出现好多次 invalid access
2. C++ 中二维数组在地址空间上是连续的
3. vector 是容器，底层实现是array

[总结图片](https://code-thinking-1253855093.file.myqcloud.com/pics/%E6%95%B0%E7%BB%84%E6%80%BB%E7%BB%93.png)

## Day 3

> 链表理论基础，203.移除链表元素，707.设计链表，206.反转链表

* [X] 203 Remove Linked List Elements (7 min)
  * 重点是要想想清楚 output 的链表的开头是哪一个
    * 可以选择一直删除直到找到一个合适的头，再循环
    * 也可以加一个dummyHead，只要注意返回需要返回dummyHead->next
* [X] 707 Design Linked List (30 min)
  * 比想象中有挑战性多了, 提交了很多次，但是好在看到test case就可以很容易很快找到问题所在
  * 我的方法是本身作为linkedlist，没有添加dummy head
    * 要注意 index的输入会导致需要考虑 `cur=head` 的指向，假如是nullptr需要单独考虑
  * 看过c哥的做法，发现加一个dummyHead其实会简单很多，一些corner cases也自然而然不需要再特别强调
* [X] 206 Reverse Linked List (5 min)
  * 经典题目，采用后面给前面可以轻松 O(n) 解决

## Day 4

> 24.两两交换链表中的节点，19.删除链表的倒数第N个节点，面试题02.07. 链表相交，142.环形链表II

* [X] 24 Swap Nodes in Pairs (11 min)
  * 最简单的方法就是给接下来的几个需要交换的都设置变量(first ptr, second ptr, etc)，然后引用reference就能很好的解决了
  * 另外需要注意的是在循环中，因为是两两交换，所以要保证交换的两个node都不是 `nullptr`
* [X] 19 Remove nth Node from End of List
  * 最直接我当时的想法是 翻转，然后删除翻转后第n个头节点，然后再翻转，但这样最多要3 passes
  * 然后打开c哥，当我看到快慢指针这四个字我就马上明白了，于是后面就没看c哥的讲解搞定了
    * 第一次尝试是没有使用dummyHead，但问题就会有的是 针对一个node的LinkedList，要想删除一个就处理起来很麻烦
    * 于是第二次尝试使用dummyHead轻松搞定
* [X] 160 Intersection of Two Linked Lists
  * 思路倒是很明确的一个题目，需要注意的是他们的差值是负数的情况下for loop循环对齐时使用的边界条件(`for(int i = diff; diff > 0; i++)`)
* [X] 142 Linked List Cycle II
  * 关键是想清楚：当快慢指针相遇时，慢指针一定没走完第一圈，因为快指针是慢指针速度的双倍
  * 在找到有相遇点之后，从头节点开始与相遇点同时进行，再次相遇点即为相交开始的点
  * [图片](https://code-thinking-1253855093.file.myqcloud.com/pics/20220925103433.png)

## Day 6

> 哈希表理论基础，242.有效的字母异位词，349. 两个数组的交集，202. 快乐数，1. 两数之和   

### 哈希表理论基础

|         集合         | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 |  查询效率  |  增删效率  |
| :------------------: | :------: | :------: | :--------------: | :----------: | :--------: | :--------: |
|      `std::set`      |  红黑树  |   有序   |        否        |      否      | $O(log n)$ | $O(log n)$ |
|   `std::multiset`    |  红黑树  |   有序   |        是        |      否      | $O(log n)$ | $O(log n)$ |
| `std::unordered_set` |  哈希表  |   无序   |        否        |      否      |   $O(1)$   |   $O(1)$   |

|        映射        | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| :----------------: | :------: | :------: | :--------------: | :----------: | :------: | :------: |
|      std::map      |  红黑树  | key有序  |   key不可重复    | key不可修改  | O(logn)  | O(logn)  |
|   std::multimap    |  红黑树  | key有序  |    key可重复     | key不可修改  | O(log n) | O(log n) |
| std::unordered_map |  哈希表  | key无序  |   key不可重复    | key不可修改  |   O(1)   |   O(1)   |

* [X] 242 Valid Anagram
  * 查找一个元素是否存在就用hash table，所以采用的是`std::unordered_map`，但针对这道题，看了C哥的才意识到可以直接用一个 `int arr[]`，比map要快
* [X] 349 Intersection of Two Arrays
  * 没什么特别的，hash map 做的话 读取都是 $O(1)$,
* [X] 202 Happy Number
  * 感觉总能找到dp那种感觉，记住以前算过
* [X] 1 Two sum
  * 两数之和，我们不断在map中找差值就可以

## Day 7

> 454.四数相加II，383. 赎金信，15. 三数之和，18. 四数之和，总结

* [X] 454 4 Sum II
  * 因为要求的是四个数相加等于0，所以相对简单，一个map来记录不同组合的次数
* [X] 383 Ransom Note
  * 没什么难度，这里注意一下因为是英文字母，所以我们用 `int map[26]` 当作map，不用真的采用 `unordered_map`
* [X] 15 3 Sum
  * 确定一个数之后，利用滑动窗口寻找其他＝0的组合，注意不一定非要是0，任意 target value 都可以
  * 可以在最开始 sort，使得我们只需要进行sort这一次，而不需要每一次确定数之后滑动窗口找其他组和都浪费时间
* [X] 18 4 Sum
  * 本质其实就是 3 Sum的变形，确定两个数之后，对剩余两个数滑动窗口



