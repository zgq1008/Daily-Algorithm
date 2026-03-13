// 动态规划
/*
    一个回文串的子串必定是回文串
    从字符串的第一个字符开始遍历 向左右扩张 且不能超出字符串范围
    奇数和偶数的右指针起始点不同
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int start = 0, end = 0;
        int l, r;
        for (int i = 0; i < s.length(); i++) {
            // 长度为奇数的回文子串
            l = r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            // 长度为偶数的回文子串
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxlen);
    }
};