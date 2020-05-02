/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int reverse(int x) {
        bool isNeg = false;
        if (x == INT32_MIN) return 0;
        if (x < 0) {
            x = -x;
            isNeg = true;
        }
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        std::reverse(s.begin(), s.end());
        ss.clear();
        ss << s;
        long long num;
        ss >> num;
        if (num > INT32_MAX || num < INT32_MIN) return 0;
        return isNeg ? -num : num;
    }
};
// @lc code=end
