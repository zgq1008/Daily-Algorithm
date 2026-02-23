//转换为字符串法
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        std::string s = std::to_string(x);//将数值转换为字符串
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};