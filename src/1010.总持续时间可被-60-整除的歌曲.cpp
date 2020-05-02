/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        int res = 0;
        for (int t : time) {
            t %= 60;
            if (t)
                res += cnt[60 - t];
            else
                res += cnt[t];
            ++cnt[t];
        }
        return res;
    }
};
// @lc code=end
