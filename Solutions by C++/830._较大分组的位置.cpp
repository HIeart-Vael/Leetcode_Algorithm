/***********************************************************************************
*
* 题目名称：830. 较大分组的位置
* 题目描述：在一个由小写字母构成的字符串 s 中，包含由一些连续的相同字符所构成的分组。
*          我们称所有包含 大于或等于三个 连续字符的分组为 较大分组 
*          找到每一个 较大分组 的区间，按起始位置下标递增顺序排序后，返回结果。
*
* 创建时间：2021-08-07 12:21
*
***********************************************************************************/
/***********************************************************************************
* 输入：s = "abcdddeeeeaabbbcd"
* 输出：[[3,5],[6,9],[12,14]]
* 解释：较大分组为 "ddd", "eeee" 和 "bbb"
***********************************************************************************/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        char prev = '#';            //一个随便的初始符号
        int count = 0;              // 记录子串长度
        int start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == prev) {
                count += 1;
            } else {
                if (count >= 3) {
                    ans.push_back({start, i-1});
                }                               // count小于3
                count = 1;                      // count重置
                prev = s[i];                    // prev更新
                start = i;                      // start更新
            }
        }
        if (count >= 3) {
            ans.push_back({start, int(s.size())-1});  // 对于 "aaa" 的解决方案
        }
        return ans;
    }
};