int maxArea(int* height, int heightSize) {
    //双指针
    int l=0,r=heightSize-1;
    int res=0;
    while (l<r)
    {
        int minheight=height[r]>height[l]?height[l]:height[r];
        int area=minheight*(r-l);
        res=res>area?res:area;
        if (height[l]>=height[r])
        //高度高的指针不动 另一个指针移动
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return res;
}