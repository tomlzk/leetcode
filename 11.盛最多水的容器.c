/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
int maxArea(int* height, int heightSize)
{
    int maxofsize = 0;
    int nowofsize = 0;
    int i = 0;
    int j = heightSize - 1;
    int lowofheight = 0;
    while(i < j)
    {
        lowofheight = height[i] > height[j] ? height[j] : height[i];
        nowofsize = (j - i)*lowofheight;
        maxofsize = maxofsize > nowofsize ? maxofsize : nowofsize;
        height[i] > height[j] ? j-- : i++;
    }
    return maxofsize;
}
// @lc code=end

