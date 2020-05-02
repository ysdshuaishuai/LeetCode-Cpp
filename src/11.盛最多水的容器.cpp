/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
static const auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int ret = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            ret = max(ret, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        return ret;
    }
};
// @lc code=end
