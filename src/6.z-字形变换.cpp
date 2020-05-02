/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0, goingDown = -1;
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = -goingDown;
            curRow += goingDown;
        }
        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
// @lc code=end
