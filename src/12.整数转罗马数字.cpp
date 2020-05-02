/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
int numTable[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string strTable[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                     "XL", "X",  "IX", "V",  "IV", "I"};

class Solution {
   public:
    string intToRoman(int num) {
        int count = 0;
        string ret;
        for (int i = 0; i < sizeof(numTable) / sizeof(int); i++) {
            count = num / numTable[i];
            while (count > 0) {
                ret.append(strTable[i]);
                num = num - numTable[i];
                count--;
            }
        }
        return ret;
    }
};
// @lc code=end
