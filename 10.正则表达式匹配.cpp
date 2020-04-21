/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        // 回溯解法 832ms
        // if (p.empty()) return s.empty();
        // bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        // if (p.size() > 1 && p[1] == '*')
        //     return isMatch(s, p.substr(2)) ||
        //            (firstMatch && isMatch(s.substr(1), p));
        // else
        //     return firstMatch && isMatch(s.substr(1), p.substr(1));

        // 正则标准库 436ms
        // regex e("^" + p + "$");
        // if (regex_match(s, e))
        //     return true;
        // else
        //     return false;

        // 动态规划解法 12ms
        if (p.empty()) return s.empty();
        int n = s.size(), m = p.size();

        // dp[i][j]: 表示s[:i]能否和p[:j]匹配
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // 初始化，形如a*b*c*d*e*这样的pattern才能匹配空串
        dp[0][0] = true;  // 空的pattern也能匹配空串
        for (int i = 1; i <= m; ++i) {
            if (p[i - 1] == '*' && dp[0][i - 2]) {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end
