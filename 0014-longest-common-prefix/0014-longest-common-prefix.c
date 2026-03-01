//判断所有字符串前n个元素是否相同 返回bool类型
bool issame(char** strs,int len,int strsSize)
{
    char* arr=strs[0];
    for (int i=1;i<strsSize;i++)
    {
        if (strncmp(arr,strs[i],len)!=0)
        {
            return false;
        }
    }
    return true;
}
char* longestCommonPrefix(char** strs, int strsSize) {
   //二分查找
   //最长字符串前缀肯定小于最短字符串的长度
   if (strsSize==0)
        return "";
    int minlen=strlen(strs[0]);
    for (int i=1;i<strsSize;i++)
    {
        if (strlen(strs[i])<minlen)
        {
            minlen=strlen(strs[i]);
        }
    }
    int low=0;
    int high=minlen;
    int mid=(low+high)/2;
    while (low<=high)
    {
        if (issame(strs,mid,strsSize))
        {
            low=mid+1;
            mid=(low+high)/2;
        }
        else
        {
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    char* arr=malloc((high+1)*sizeof(char));
    strncpy(arr,strs[0],high);
    arr[high]='\0';
    return arr;
}