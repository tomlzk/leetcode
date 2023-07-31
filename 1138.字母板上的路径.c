/*
 * @lc app=leetcode.cn id=1138 lang=c
 *
 * [1138] 字母板上的路径
 */

// @lc code=start

char *alphabetBoardPath(char *target)
{
    int maxoftarget = strlen(target);
    char *array = (char *)malloc(sizeof(char) * 10000);
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int k = 0;
    int index = 0;
    int number = 0;
    while (k < maxoftarget)
    {
        number = target[k] - 'a';
        m = number / 5;
        n = number % 5;

        if (m < 5 || (m == 5 && n == j))
        {
            while (m != i)
            {
                if (m > i)
                {
                    array[index] = 'D';
                    i++;
                    index++;
                }
                else if (m < i)
                {
                    array[index] = 'U';
                    i--;
                    index++;
                }
            }

            while (n != j)
            {
                if (n > j)
                {
                    array[index] = 'R';
                    index++;
                    j++;
                }
                else if (n < j)
                {
                    array[index] = 'L';
                    index++;
                    j--;
                }
            }
        }
        else
        {
            while(i < 4)
            {
                array[index] = 'D';
                i++;
                index++;
            }

             while (n != j)
            {
                if (n > j)
                {
                    array[index] = 'R';
                    index++;
                    j++;
                }
                else if (n < j)
                {
                    array[index] = 'L';
                    index++;
                    j--;
                }
            }

            array[index] = 'D';
            index++;
            i++;
        }

        array[index] = '!';
        index++;
        k++;
    }
    array[index] = '\0';
    return array;
}
// @lc code=end
