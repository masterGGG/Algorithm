/*
实现 strStr() 函数。
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

示例 1：
输入：haystack = "hello", needle = "ll"、
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) {
            return 0;
        } else if (haystack.length() == 0 || haystack.length() < needle.length()) {
            return -1;
        }

        int pos = 0;
        int tail = haystack.length() - needle.length() + 1;

        while (pos < tail) {
            if (haystack[pos] == needle[0]) {
                int i = 1;

                while (i < needle.length() && haystack[pos + i] == needle[i]) {
                    i++;
                }

                if (i == needle.length()) {
                    return pos;
                }
            }

            pos++;
        }

        return -1;
    }
};