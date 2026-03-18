//先排序 再使用双指针
int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int i,l,r;
    int closestsum=nums[0]+nums[1]+nums[2];
    for (i=0;i<numsSize-2;i++)
    {
        l=i+1;
        r=numsSize-1;
        while(l<r)
        {
            int currentsum=nums[i]+nums[l]+nums[r];
            if (currentsum==target)
            {
                return currentsum;
            }
            if (abs(currentsum-target)<abs(closestsum-target))
            {
                closestsum=currentsum;
            }
            if (currentsum<target)
            {
                l++;
            }
            else{
                r--;
            }
        }
    }
    return closestsum;
}