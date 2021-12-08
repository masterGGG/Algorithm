/*
423. 从英文中重建数字
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。

示例 1：
输入：s = "owoztneoer"
输出："012"
示例 2：
输入：s = "fviefuro"
输出："45"
 

提示：

1 <= s.length <= 105
s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一
s 保证是一个符合题目要求的字符串
*/
/*
z  e  r  o
o  n  e
t  w  o
t  h  r  e  e
f  o  u  r
f  i  v  e
s  i  x
s  e  v  e  n
e  i  g  h  t
n  i  n  e

z 1
e 8
r 3
o 4
n 3
t 3
w 1
h 2
f 2
u 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    static std::vector<std::string> g_vec_;

    bool eraseString(std::string str, std::unordered_map<char, int> &map_) {
        for (auto c : str) {
            if (map_.find(c) == map_.end() || map_[c] == 0) {
                return false;
            }
        }

        for (auto c : str) {
            map_[c]--;
        }

        return true;
    }

    std::string originalDigits(std::string s) {
        std::string digit_;
        std::unordered_map<char, int> map_;
        for (auto c : s) {
            if (map_.find(c) == map_.end()) {
                map_[c] = 1;
            } else {
                map_[c]++;
            }
        }

        for (int i = 0; i < g_vec_.size(); ) {
            if (eraseString(g_vec_[i], map_)) {
                digit_ += std::to_string(i);
            } else {
                i++;
            }
        }

        return digit_;
    }
};

std::vector<std::string> Solution::g_vec_{"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    Solution s;
    std::cout << s.originalDigits("zeroonetwothreefourfivesixseveneightnine") << std::endl;
    return 0;
}