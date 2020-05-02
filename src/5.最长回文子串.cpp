/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        string tmp = "$#";
        for (char c : s) {
            tmp.push_back(c);
            tmp.push_back('#');
        }
        int id = 0, mx = 0, n = tmp.size(), maxCenter, maxLen = 0;
        vector<int> p(n);
        for (int i = 1; i < n; ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (tmp[i - p[i]] == tmp[i + p[i]]) ++p[i];
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
                if (p[i] > maxLen) {
                    maxLen = p[i];
                    maxCenter = i;
                }
            }
        }
        return s.substr((maxCenter - maxLen) / 2, maxLen - 1);
    }
};
// @lc code=end
