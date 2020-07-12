# My LeetCode
My LeetCode Solutions


## Some Description
1. The runtime and memory in LeetCode is not correct, ignore it directly. LeetCode的运行时间和内存不准，直接忽略。



## 01. Two Sum
### 题目
https://leetcode.com/problems/two-sum
### 思路
核心思想是`map`的使用
1. 将`x[i]`的值保存到`map<int,int>`中，map的第一个元素为`x[i]`，第二个元素为index `i`.
1. 通过一次循环，先检查`sum - x[i]`是否存在于`map`中，存在则返回index，否则，将`<x[i], i>`加入`map`.

## 02. Add Two Numbers
### 题目
https://leetcode.com/problems/add-two-numbers/
### 思路
1. 直接相加就行了，注意处理几种特殊情况。
    - `l1`和`l2`长度不一样，或有一为空. 如｀[0,1]+[0,1,2]`，或`[] + [0,1]`
    - 最高位有进位