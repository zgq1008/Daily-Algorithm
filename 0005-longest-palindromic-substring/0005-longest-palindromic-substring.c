// 判断 s[left...right] 这一段是否为回文
bool isPs(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0)
        return "";  
    int maxLen = 0;
    int startIdx = 0; // 记录最长回文子串的起始位置 
    for (int l = 0; l < len; l++) {
        for (int r = l; r < len; r++) {
            if (isPs(s, l, r) && (r - l + 1 > maxLen)) {
                maxLen = r - l + 1;
                startIdx = l;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + startIdx, maxLen);
    result[maxLen] = '\0'; 
    return result;
}