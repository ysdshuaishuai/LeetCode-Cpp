/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                ret[0] = m[target - nums[i]];
                ret[1] = i;
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};
// @lc code=end
