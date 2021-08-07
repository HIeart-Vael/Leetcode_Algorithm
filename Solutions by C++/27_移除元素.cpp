/***********************************************************************************
*
* 题目名称：27. 移除元素
* 题目描述：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
*          并返回移除后数组的新长度。
*
* 创建时间：2021-08-07 12:31
*
***********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
    }
};