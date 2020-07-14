# My LeetCode
My LeetCode Solutions

[TOC]


## Some Description
1. The runtime and memory in LeetCode is not correct, ignore it directly. LeetCode的运行时间和内存不准，直接忽略。


## 01. Two Sum
### 题目
两数之和
https://leetcode.com/problems/two-sum
### 思路
核心思想是`map`的使用
1. 将`x[i]`的值保存到`map<int,int>`中，map的第一个元素为`x[i]`，第二个元素为index `i`.
1. 通过一次循环，先检查`sum - x[i]`是否存在于`map`中，存在则返回index，否则，将`<x[i], i>`加入`map`.

## 02. Add Two Numbers
### 题目
两数相加
https://leetcode.com/problems/add-two-numbers/
### 思路
1. 直接相加就行了，注意处理几种特殊情况。
    - `l1`和`l2`长度不一样，或有一为空. 如｀[0,1]+[0,1,2]`，或`[] + [0,1]`
    - 最高位有进位

### 3. Longest Substring Without Repeating Characters
### 题目
计算字符串中最长的无重复字符子串
https://leetcode.com/problems/longest-substring-without-repeating-characters/
### 思路
#### 暴力匹配
1. `i`从`0`循环到`n`
1. `j`从`i`循环到`n`，默认只包含256个字符，使用`bitset<256>`来检查`s[j]`是否每个字符是否存在，存在即将该位置位。存在即退出，并计算匹配长度

#### 使用滑动窗口
1. 同样使用`bitset<256>`来存储当前子串中某个字符是否存在
1. `i`从`0`循环到`n`, `j`从`0`循环到`n`，依次检查字符`s[j]`是否存在，
    - 不存在，将`bitset[s[j]]`置位，`j=j+1`，并计算匹配长度
    - 存在，将`bits[i]`复位，`i=i+1`
#### 优化的滑动窗口方法
1. 与滑动窗口方法相比，当检查$[i,j)$无重复字符，当将$s[j]$加入时，则存在重新字符，则说明$[i,j)$中存在$s[j']$与$s[j]$相同，则令$i= \max(j', i+1)$，从而加速循环。因此使用`array<int, 256>`来保存字符存在的位置，检查条件为`arr[s[j]]>=ｉ`。
1. 只有刚存在重复字符时计算匹配长度，注意循环退出(`i < n && j < n`)时需要再检查一遍.