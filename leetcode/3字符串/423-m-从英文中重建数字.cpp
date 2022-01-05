/*
423. 从英文中重建数字
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字
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

思路：每个字母分别在哪些数字中出现
z, w, u, x, g 都只在一个数字中，即0,2,4,6,8 中出现
h 只在 3,8 中出现。由于我们已经知道了 8 出现的次数，因此可以计算出 3 出现的次数。
f 只在 4,5 中出现。由于我们已经知道了 4 出现的次数，因此可以计算出 5 出现的次数。
s 只在6,7 中出现。由于我们已经知道了 6 出现的次数，因此可以计算出 7 出现的次数。
*/
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};