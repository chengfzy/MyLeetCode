# 01. Two Sum
## 题目
两数之和
https://leetcode.com/problems/two-sum

## 思路
核心思想是`map`的使用
1. 将$x[i]$的值保存到`map<int, int>`中, map的第一个元素为$x[i]$, 第二个元素为index $i$.
1. 通过一次循环, 先检查$sum - x[i]$是否存在于`map`中, 存在则返回index, 否则, 将$<x[i], i>$加入`map`.
