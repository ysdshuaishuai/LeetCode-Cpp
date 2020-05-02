/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0x3f3f3f3f, n = nums.size();
        for (int i = 0; i <= n - 3; ++i) {
            int p1 = i + 1, p2 = n - 1;
            while (p1 < p2) {
                int sum = nums[i] + nums[p1] + nums[p2];
                if (sum == target)
                    return sum;
                else {
                    res = abs(sum - target) < abs(res - target) ? sum : res;
                    if (sum > target)
                        --p2;
                    else
                        ++p1;
                }
            }
            while (i <= n - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};
// @lc code=end
