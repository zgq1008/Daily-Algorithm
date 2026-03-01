char* longestCommonPrefix(char** strs, int strsSize) {
    //纵向扫描法
    //二维数组
    if (strsSize==0)
        return "";
    char* arr=malloc(201*sizeof(char));
    int i;
    for (i=0;strs[0][i]!='\0';i++)//遍历第一行字符串元素
    {
        char ch=strs[0][i];
        for (int j=1;j<strsSize;j++)//遍历后续每一行字符串元素
        {
            if (strs[j][i]!=ch || strs[j][i]=='\0')
            {
                strncpy(arr,strs[0],i);
                arr[i]='\0';
                return arr;
            }
        }
    }
    //循环结束 第一行字符串就是最长前缀
    int len=strlen(strs[0]);
    strcpy(arr,strs[0]);
    arr[len]='\0';
    return arr;
}
