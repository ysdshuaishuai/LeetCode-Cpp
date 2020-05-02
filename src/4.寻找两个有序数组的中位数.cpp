/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = nums1.size(), mid1, mid2;
        int k = (nums1.size() + nums2.size() + 1) / 2;
        while (low <= high) {
            mid1 = (low + high) / 2;
            mid2 = k - mid1;
            if (mid1 > 0 && nums1[mid1 - 1] > nums2[mid2]) {
                high = mid1 - 1;
            } else if (mid1 < nums1.size() && nums1[mid1] < nums2[mid2 - 1]) {
                low = mid1 + 1;
            } else {
                break;
            }
        }
        int midLeft, midRight;
        if (mid1 == 0) {
            midLeft = nums2[mid2 - 1];
        } else if (mid2 == 0) {
            midLeft = nums1[mid1 - 1];
        } else {
            midLeft = max(nums2[mid2 - 1], nums1[mid1 - 1]);
        }
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return midLeft;
        }
        if (mid1 == nums1.size()) {
            midRight = nums2[mid2];
        } else if (mid2 == nums2.size()) {
            midRight = nums1[mid1];
        } else {
            midRight = min(nums2[mid2], nums1[mid1]);
        }
        return 1.0 * (midLeft + midRight) / 2;
    }
};
// @lc code=end
