/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                    return res;
                }
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};
// @lc code=end
