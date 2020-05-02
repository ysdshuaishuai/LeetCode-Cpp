/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
vector<string> letter{"",    "",    "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
   public:
    void dfs(vector<string>& res, string digits, string s, int k) {
        if (s.size() == digits.size()) {
            res.push_back(s);
        } else {
            for (char c : letter[digits[k] - '0']) {
                dfs(res, digits, s + c, k + 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        dfs(res, digits, "", 0);
        return res;
    }
};
// @lc code=end
