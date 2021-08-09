/***********************************************************************************
*
* 题目名称： 45. 把数组排成最小的数
* 题目描述： 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
*
* 创建时间： 2021-08-09 15:06
*
***********************************************************************************/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string x, string y) { // 排序规则，以字符串拼接的值大小作为排序依据
    return x+y < y+x;
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;
        for (auto i : nums) {
            str.push_back(to_string(i));
        }
        sort(str.begin(), str.end(), compare);
        // 使用C++匿名函数
        // sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });

        string res;
        for (auto i : str) {
            res += i;
        }
        return res;
    }
};
