/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
char * longestCommonPrefix(char ** strs, int strsSize)
{
    char *array;
    array = (char *)malloc(sizeof(char)*200);
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int temp = 0;
    int min = 201;
    while(m < strsSize)
    {
        temp = strlen(strs[m]);
        min = min > temp ? temp : min;
        m++;
    }
    printf("%d", min);
    while(i <= min)
    {
        j = 0;
        while(j + 1 < strsSize && strs[j][i] == strs[j + 1][i])
        {
            j++;
        }
        
        if(j + 1 == strsSize)
        {
            array[i] = strs[j][i]; 
        }
        else
        {
            break;
        }

        i++;
    }

    array[i] = '\0';
    return array;
}
// @lc code=end

