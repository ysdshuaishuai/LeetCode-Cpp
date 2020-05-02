/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int left = 0, ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto f = m.find(s[i]);
            if (f != m.end()) {
                left = max(left, f->second + 1);
            }
            ret = max(ret, i - left + 1);
            m[s[i]] = i;
        }
        return ret;
    }
};
// @lc code=end
