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