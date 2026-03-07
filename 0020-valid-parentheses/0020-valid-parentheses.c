bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }
    int k = 0, i = 0;
    char arr[10000];
    while (s[i] != '\0') {
        char ch=s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            arr[k++] = ch;
        } else {
            if(k==0)
                return false;
            if (ch == ')' && arr[k - 1] == '(')
                k--;
            else if (ch == ']' && arr[k - 1] == '[')
                k--;
            else if(ch=='}'&&arr[k-1]=='{') {
                k--;
            }
            else
                return false;
        }
        i++;
    }
    return k == 0;
}