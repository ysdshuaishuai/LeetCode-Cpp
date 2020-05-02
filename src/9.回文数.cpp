/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long tmp = x, num = 0;
        while (tmp) {
            num = num * 10 + tmp % 10;
            tmp /= 10;
        }
        return num == x;
    }
};
// @lc code=end
