/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n - 3; ++i) {
            int p1 = i + 1, p2 = n - 1;
            int target = 0 - nums[i];
            while (p1 < p2) {
                int sum = nums[p1] + nums[p2];
                if (sum < target)
                    ++p1;
                else if (sum > target)
                    --p2;
                else {
                    res.push_back({nums[i], nums[p1], nums[p2]});
                    while (p1 < p2 && nums[p1] == nums[p1 + 1]) ++p1;
                    while (p1 < p2 && nums[p2] == nums[p2 - 1]) --p2;
                    ++p1, --p2;
                }
            }
            while (i <= n - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};
// @lc code=end
