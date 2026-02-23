bool isPalindrome(int x) {
    if (x < 0 || ((x % 10) == 0 && x != 0))
        return false;
    int left = x;
    int right = 0;
    int temp = 0;
    while (left > right) {
        temp = left % 10;
        left = left / 10;
        right = right * 10 + temp;
    }
    if (left == right || (left == (right / 10)))//数字的位数为偶数 和 数字的位数为奇数
        return true;
    else
        return false;
}