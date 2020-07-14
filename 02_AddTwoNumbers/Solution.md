# 02. Add Two Numbers
## 题目
两数相加
https://leetcode.com/problems/add-two-numbers/

## 思路
直接相加就行了, 注意处理几种特殊情况.
- $l_1$和$l_2$长度不一样, 或有一为空. 如$[0,1]+[0,1,2]$, 或$[] + [0,1]$
- 最高位有进位