/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int isNum(char c) { return c >= '0' && c <= '9'; }

    int myAtoi(string str) {
        // 可以用stringstream很简单的实现，但是毕竟是练习算法，还是用一下普通方法。
        bool isNeg = false;
        int i = 0, n = str.size();
        long long num = 0;

        // 去空格
        while (i < n && str[i] == ' ') ++i;
        if (i == n) return 0;

        // 去正负号
        if (str[i] == '-') {
            isNeg = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        if (!isNum(str[i])) return 0;

        while (i < n && isNum(str[i])) {
            num = num * 10 + str[i++] - '0';
            if (num > INT32_MAX) break;
        }

        if (num > INT32_MAX) return isNeg ? INT32_MIN : INT32_MAX;
        return isNeg ? -num : num;
    }
};
// @lc code=end
