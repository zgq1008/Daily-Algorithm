char* convert(char* s, int numRows) {
    int len = strlen(s);
    int index = 0;
    if (len == 1 || len < numRows || numRows == 1) {
        return s;
    }
    int cyclelen = 2 * numRows - 2; // 一个竖排加一个斜排为一组 n+n-2
    char* res = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cyclelen) {
            // 第一行和第numRows行 以及中间行中处于竖排位置的元素
            res[index++] = s[i + j];
            // 处于斜排的元素（非头和尾）
            if (i != 0 && i < numRows - 1 && j + cyclelen - i < len) {
                //保证在同一行
                res[index++] = s[j + cyclelen - i];
            }
        }
    }
    res[index] = '\0';
    return res;
}