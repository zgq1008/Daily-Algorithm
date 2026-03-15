int maxArea(int* height, int heightSize) {
    //双指针
    int l=0,r=heightSize-1;
    int res=0;
    while (l<r)
    {
        int minheight=height[r]>height[l]?height[l]:height[r];
        int area=minheight*(r-l);
        res=res>area?res:area;
        while(l<r&&height[l]<=minheight)
        {
            l++;
        }
        while(l<r&&height[r]<=minheight)
        {
            r--;
        }
    }
    return res;
}