# 3. Longest Substring Without Repeating Characters
## 题目
计算字符串中最长的无重复字符子串
https://leetcode.com/problems/longest-substring-without-repeating-characters/

## 思路
### 暴力匹配
1. $i:=0 \dots n$
1. $j:=1 \dots n$, 默认只包含256个字符, 使用`bitset<256>`来检查$s[j]$是否每个字符是否存在, 存在即将该位置位.存在即退出, 并计算匹配长度

### 使用滑动窗口
1. 同样使用`bitset<256>`来存储当前子串中某个字符是否存在
1. $i:=0 \dots n, j:=0 \dots n$, 依次检查字符$s[j]$是否存在, 
    - 不存在, 将$\mathtt{bits}[s[j]]$置位, $j+1\rightarrow j$, 并计算匹配长度.
    - 存在, 将$\mathtt{bits}[i]$复位, $i+1 \rightarrow i$.

### 优化的滑动窗口方法
1. 与滑动窗口方法相比, 当检查$[i,j)$无重复字符, 当将$s[j]$加入时, 则存在重新字符, 则说明$[i,j)$中存在$s[j']$与$s[j]$相同, 则令$i= \max(j', i+1)$, 从而加速循环.因此使用`array<int, 256>`来保存字符存在的位置, 检查条件为$\mathtt{arr}[s[j]] \ge i$.
1. 只有当存在重复字符时计算匹配长度, 注意循环退出($i < n \text{ and } j < n$)时需要再检查一遍.
