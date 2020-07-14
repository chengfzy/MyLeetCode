# My LeetCode
My LeetCode Solutions

[TOC]


## Some Description
1. The runtime and memory in LeetCode is not correct, ignore it directly. LeetCode的运行时间和内存不准, 直接忽略.
1. 值得反复练习的题目
    - 04

## 01. Two Sum
### 题目
两数之和
https://leetcode.com/problems/two-sum
### 思路
核心思想是`map`的使用
1. 将`x[i]`的值保存到`map<int,int>`中, map的第一个元素为`x[i]`, 第二个元素为index `i`.
1. 通过一次循环, 先检查`sum - x[i]`是否存在于`map`中, 存在则返回index, 否则, 将`<x[i], i>`加入`map`.


## 02. Add Two Numbers
### 题目
两数相加
https://leetcode.com/problems/add-two-numbers/
### 思路
1. 直接相加就行了, 注意处理几种特殊情况.
    - `l1`和`l2`长度不一样, 或有一为空. 如｀[0,1]+[0,1,2]`, 或`[] + [0,1]`
    - 最高位有进位


## 3. Longest Substring Without Repeating Characters
### 题目
计算字符串中最长的无重复字符子串
https://leetcode.com/problems/longest-substring-without-repeating-characters/
### 思路
#### 暴力匹配
1. `i`从`0`循环到`n`
1. `j`从`i`循环到`n`, 默认只包含256个字符, 使用`bitset<256>`来检查`s[j]`是否每个字符是否存在, 存在即将该位置位.存在即退出, 并计算匹配长度

#### 使用滑动窗口
1. 同样使用`bitset<256>`来存储当前子串中某个字符是否存在
1. `i`从`0`循环到`n`, `j`从`0`循环到`n`, 依次检查字符`s[j]`是否存在, 
    - 不存在, 将`bitset[s[j]]`置位, `j=j+1`, 并计算匹配长度
    - 存在, 将`bits[i]`复位, `i=i+1`
#### 优化的滑动窗口方法
1. 与滑动窗口方法相比, 当检查$[i,j)$无重复字符, 当将$s[j]$加入时, 则存在重新字符, 则说明$[i,j)$中存在$s[j']$与$s[j]$相同, 则令$i= \max(j', i+1)$, 从而加速循环.因此使用`array<int, 256>`来保存字符存在的位置, 检查条件为`arr[s[j]]>=ｉ`.
1. 只有刚存在重复字符时计算匹配长度, 注意循环退出(`i < n && j < n`)时需要再检查一遍.


## 4. Median of Two Sorted Arrays
### 题目
寻找两个正序数组的中位数
https://leetcode.com/problems/median-of-two-sorted-arrays/
### 思路
由于题目要求计算复杂度$\mathcal{O}(\log(m+n))$, 通常会采用二分法来处理.
将数组$a$和$b$拆分成左右两部分, 
$$
\begin{aligned}
    \mathrm{Left} \quad|\quad& \mathrm{Right} \\
    a[0], \dots, a[i-1] \quad|\quad& a[i], \dots, a[m-1] \\
    b[0], \dots, b[j-1] \quad|\quad& b[j], \dots, b[n-1]
\end{aligned}
$$
定义
$$
\begin{aligned}
    \mathtt{maxLeft} =& \max(a[i-1], b[j-1]) \\
    \mathtt{minRight} =& \min(a[j], b[j])
\end{aligned}
$$
根据中位数的定义, 有
1. 当$m+n$为偶数时,
    $$
    \begin{aligned}
        \mathtt{len}(\mathrm{Left}) =& \mathtt{len}(\mathrm{Right}) \\
        \mathtt{maxLeft} \le& \mathtt{minRight} \\
        \mathtt{median} =& \frac{\mathtt{maxLeft} + \mathtt{minRight}}{2} 
    \end{aligned}
    $$
1. 当$m+n$为奇数时,
    $$
    \begin{aligned}
        \mathtt{len}(\mathrm{Left}) =& \mathtt{len}(\mathrm{Right}) + 1 \\
        \mathtt{maxLeft} \le& \mathtt{minRight} \\
        \mathtt{median} =& \mathtt{maxLeft}
    \end{aligned}
    $$

由情况1有$i+j = m-i+n-j \Rightarrow i+j = \frac{m+n}{2}$；有情况2有$i+j = m-i+n-j+1 \Rightarrow i+j = \frac{m+n+1}{2}$.综合两种情况, 得$i+j = \frac{m+n+1}{2}$, 这里的分数只保留整数部分.

程序设计时, 可以只对$i$进行二分查找, 设初始值$i_0 = 0, i_1 = m$, 从而计算出$i = \frac{i_0 + i_1}{2}, j = \frac{m+n+1}{2} - 1$, 并检查是否满足条件$\mathtt{maxLeft} \le \mathtt{minRight}$.该条件可以拆成三种情况
1. $a[i-1] > b[j]$, 在Left二分查找, 设$i-1 \rightarrow i$.
1. $b[j-1] > a[i]$, 在Rightf二分查找, 设$i+1\rightarrow i$.
1. 其他, $a[i-1] \le b[j] \text{ and } b[j-1] \le a[i]$, 已经找到, 退出.

需要注意以下两点
1. $i, i+1, j, j+1$可能越界, 若越界则将该数设成最大或最小值, 比如$\mathtt{max_{int}} \rightarrow a[i]$.
1. 需同时检查条件$i_0 < i_1$.