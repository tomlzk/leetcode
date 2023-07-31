/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start


char * convert(char * s, int numRows)
{
    s[10000] = 1;
    int length = strlen(s);
    char array[numRows][1000000 / numRows + 1];
    int i = 0;
    int j = -1;
    int k = 0;
    int n = -1;
    int len = 0;
    int temp = -2;
    char arr[1000] = {'\0'};
    for(i = 0; i < numRows; i++)
    {
        for(j = 0; j < 1000000 / numRows + 1; j++)
        {
            array[i][j] = '\0';
        }
    }
    i = 0;
    j = -1;
    while(n < length)
    {
        if(temp == n)
        {
            break;
        }
        temp = n;
        if(j >= numRows - 1)
        {
            while(j > 0 && n < length)
            {
                i++;
                n++;
                j--;
                array[j][i] = s[n];
            }
        }
        else
        {
            while(j < numRows - 1 && n < length)
            {
                n++;
                j++;
                array[j][i] = s[n];
            }
        }
    }
    len = i;
    for(i = 0; i < numRows; i++)
    {
        for(j = 0; j <= len; j = j + 1)
        {
            if(array[i][j] != '\0')
            {
                s[k] = array[i][j];
                k++;
            }
            
        }
    }
    
    return s;
}
// @lc code=end

