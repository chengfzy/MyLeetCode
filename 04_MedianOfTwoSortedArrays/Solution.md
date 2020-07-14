# 4. Median of Two Sorted Arrays
## 题目
寻找两个正序数组的中位数
https://leetcode.com/problems/median-of-two-sorted-arrays/

## 思路
### 二分查找
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
1. $m \le n$, 若$m > n$， 将数据交换后再查找中位数.

### 第k小数解法
TODO