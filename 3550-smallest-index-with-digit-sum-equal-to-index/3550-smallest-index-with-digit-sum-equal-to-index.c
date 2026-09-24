int sumCount(int num){
    int count=0;
    while(num>0){
        count+=num%10;
        num=num/10;
    }
    return count;
}

int smallestIndex(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++)
    {
        if (sumCount(nums[i])==i){
            return i;
        }
    }
    return -1;
}

