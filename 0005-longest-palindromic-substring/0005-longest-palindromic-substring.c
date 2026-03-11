//中心扩散法
//回文串分为奇数中心点和偶数中心点
//判断是否为回文串
int isPS(char* s,int left,int right)
{
    int len=strlen(s);
    while (left>=0&&right<len)
    {
        if (s[left]!=s[right])
        {
            break;
        }
        left--;
        right++;
    }
    //当循环结束时 left和right所在位置已经是不匹配了
    //应该返回right-1-(left+1)+1(主函数传递的i)
    return right-left-1;
}
char* longestPalindrome(char* s) {
    int len=strlen(s);
    int start=0,end=0;
    for (int i=0;i<len;i++)
    {
        //奇数中心点
        int len1=isPS(s,i,i);
        //偶数中心点
        int len2=isPS(s,i,i+1);
        int maxlen=len1>len2?len1:len2;
        if(maxlen>end-start+1)//如果本次长度大于上次循环的最大长度
        {
            start=i-((maxlen-1)/2);//最大长度算上了自己 所以要减1(isPS函数最后一句)
            end=i+maxlen/2;//
        }
    }
    int len3=end-start+1;
    char* arr=malloc(sizeof(char)*(len3+1));
    strncpy(arr,s+start,len3);
    arr[len3]='\0';
    return arr;
}