/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
int lengthOfLongestSubstring(char * s)
{
    int maxofs = strlen(s);
    int array[128] = {0};
    int right = 0;
    int left = 0;
    int sum = 0;
    int now = 0;
    while(right < maxofs && left < maxofs)
    {
        if(array[s[right]] == 0)
        {
            array[s[right]] = 1;
            right++;
            now++;
            
        }
        else
        {
            array[s[left]] = 0;
            now--;
            left++;

        }
        sum = sum > now ? sum : now;
    }
    return sum;
    return 0;
}
// @lc code=end

