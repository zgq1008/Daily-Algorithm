int romanToInt(char* s) {
    int len = strlen(s);
    int count = 0;
    char arr, temp;
    int i = 0;
    while (i < len) {
        arr = s[i];
        if (arr == 'I') {
            temp = s[i + 1];
            if (temp == 'V') {
                count += 4;
                i += 2;
            } else if (temp == 'X') {
                count += 9;
                i += 2;
            } else {
                count += 1;
                i++;
            }
        } else if (arr == 'V') {
            count += 5;
            i++;
        } else if (arr == 'X') {
            temp = s[i + 1];
            if (temp == 'L') {
                count += 40;
                i += 2;
            } else if (temp == 'C') {
                count += 90;
                i += 2;
            } else {
                count += 10;
                i++;
            }
        } else if (arr == 'L') {
            count += 50;
            i++;
        } else if (arr == 'C') {
            temp = s[i + 1];
            if (temp == 'D') {
                count += 400;
                i += 2;
            } else if (temp == 'M') {
                count += 900;
                i += 2;
            } else {
                count += 100;
                i++;
            }
        } else if (arr == 'D') {
            count += 500;
            i++;
        } else if (arr == 'M') {
            count += 1000;
            i++;
        }
    }
    return count;
}