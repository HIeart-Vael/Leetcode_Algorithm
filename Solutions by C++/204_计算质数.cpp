/***********************************************************************************
*
* 题目名称：204. 计数质数
* 题目描述：统计所有小于非负整数 n 的质数的数量。
*
* 创建时间：2021-08-07 12:22
*
***********************************************************************************/

#include <algorithm>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        bool *a = new bool [n + 2];

        // fill()函数参数：fill(first, last, val);
        // first 为容器的首迭代器，
        // last为容器的末迭代器，
        // val为将要替换的值。
        fill(a, a + n, true);  // 将a首地址开始的n个存储单元标记为true, 末迭代器为 (a+下标) + 1
        a[0] = false;
        a[1] = false;
        for (int i = 2; i < n; i++) {
            if (a[i]) { // 已标记跳过,被标记执行
                count ++;
                for (int j = i * 2; j < n; j += i) {  // 将2i, 3i, 4i...全部标记为false
                    a[j] = false;
                }
            }
        }
        return count;
    }
};