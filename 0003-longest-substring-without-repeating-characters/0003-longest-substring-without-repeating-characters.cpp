class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口
        int left = 0, right = 0;
        int maxlen = 0;
        unordered_set<char> arr; // 建立哈希集合
        for (right = 0; right < s.length(); right++) {
            char ch = s[right];
            while (arr.count(ch) > 0) // 判断元素是否重复出现 大于零代表存在
            {
                arr.erase(s[left]); // 将左边界字符移出集合
                left++;             // 缩小窗口
            }
            arr.insert(ch);
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};