/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1, mp['V'] = 5;
        mp['X'] = 10, mp['L'] = 50;
        mp['C'] = 100, mp['D'] = 500;
        mp['M'] = 1000;
        int res = 0, n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (mp[s[i]] < mp[s[i + 1]])
                res -= mp[s[i]];
            else
                res += mp[s[i]];
        }
        return res + mp[s[n - 1]];
    }
};
// @lc code=end
