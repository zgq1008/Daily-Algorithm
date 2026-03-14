int reverse(int x) {
    int maxnum = 2147483647;
    int minnum = -2147483648;
    int temp = 0;
    int res = 0;
    while (x != 0) {
        temp = x % 10;
        //将判断语句写在赋值语句之前 防止res超出int范围
        if (res > maxnum / 10 || (res == maxnum / 10 && temp > 7))
            return 0;
        if (res < minnum / 10 || (res == minnum / 10 && temp > 8))
            return 0;
        res = res * 10 + temp;
        x = x / 10;
    }
    return res;
}