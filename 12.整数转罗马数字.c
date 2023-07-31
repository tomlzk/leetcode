/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
char *five(char array[], int num, int i);
char *fiveten(char array[], int num, int i);
char *tenfifty(char array[], int num, int i);
char *fiftyhundred(char array[], int num, int i);
char *hundredfivehundred(char array[], int num, int i);
char *fivehundredthousand(char array[], int num, int i);
char *thousand(char array[], int num, int i);

char *intToRoman(int num)
{

    char *array;
    array = malloc(sizeof(char) * 100);
    int i = 0;

    if (num >= 0 && num < 5)
    {
        five(array, num, i);
    }
    else if (num >= 5 && num < 10)
    {
        fiveten(array, num, i);
    }
    else if (num >= 10 && num < 50)
    {
        tenfifty(array, num, i);
    }
    else if (num >= 50 && num < 100)
    {
        fiftyhundred(array, num, i);
    }
    else if (num >= 100 && num < 500)
    {
        hundredfivehundred(array, num, i);
    }
    else if (num >= 500 && num < 1000)
    {
        fivehundredthousand(array, num, i);
    }
    else if (num >= 1000)
    {
        thousand(array, num, i);
    }
    printf("%p\n", array);
    int j = 0;
    while (array[j] != '\0')
    {
        printf("%c", array[j]);
        j++;
    }
    return array;
}

char *five(char array[], int num, int i)
{
    if (num == 4)
    {
        array[i] = 'I';
        i++;
        array[i] = 'V';
        i++;
        array[i] = '\0';
        i++;
    }
    else
    {
        while (num > 0)
        {
            array[i] = 'I';
            num--;
            i++;
        }
        array[i] = '\0';
    }

    return array;
}

char *fiveten(char array[], int num, int i)
{
    if (num == 9)
    {
        array[i] = 'I';
        i++;
        array[i] = 'X';
        i++;
        array[i] = '\0';
        i++;
    }
    else
    {
        array[i] = 'V';
        i++;
        num = num - 5;
        five(array, num, i);
    }

    return array;
}

char *tenfifty(char array[], int num, int i)
{
    if (num >= 40)
    {
        array[i] = 'X';
        i++;
        array[i] = 'L';
        i++;
        num = num - 40;
    }
    else
    {
        while (num >= 10)
        {
            array[i] = 'X';
            i++;
            num = num - 10;
        }
    }

    if (num >= 5)
    {
        fiveten(array, num, i);
    }
    else if (num < 5 && num >= 0)
    {
        five(array, num, i);
    }

    return array;
}

char *fiftyhundred(char array[], int num, int i)
{
    if (num >= 90)
    {
        array[i] = 'X';
        i++;
        array[i] = 'C';
        i++;
        num = num - 90;
        if (num >= 5)
        {
            fiveten(array, num, i);
        }
        else if (num < 5 && num >= 0)
        {
            five(array, num, i);
        }
    }
    else
    {
        array[i] = 'L';
        i++;
        num = num - 50;

        tenfifty(array, num, i);
    }

    return array;
}

char *hundredfivehundred(char array[], int num, int i)
{
    if (num >= 400)
    {
        array[i] = 'C';
        i++;
        array[i] = 'D';
        i++;
        num = num - 400;
    }
    else
    {
        while (num >= 100)
        {
            array[i] = 'C';
            i++;
            num = num - 100;
        }
    }

    if (num >= 50)
    {
        fiftyhundred(array, num, i);
    }
    else if (num < 50 && num >= 0)
    {
        tenfifty(array, num, i);
    }

    return array;
}

char *fivehundredthousand(char array[], int num, int i)
{
    if (num >= 900)
    {
        array[i] = 'C';
        i++;
        array[i] = 'M';
        i++;
        num = num - 900;
        if (num >= 50)
        {
            fiftyhundred(array, num, i);
        }
        else if (num < 50 && num >= 0)
        {
            tenfifty(array, num, i);
        }
    }
    else
    {
        array[i] = 'D';
        i++;
        num = num - 500;

        hundredfivehundred(array, num, i);
    }

    return array;
}

char *thousand(char array[], int num, int i)
{
    while (num >= 1000)
    {
        array[i] = 'M';
        i++;
        num = num - 1000;
    }

    if (num >= 500)
    {
        fivehundredthousand(array, num, i);
    }
    else if (num < 500 && num >= 0)
    {
        hundredfivehundred(array, num, i);
    }

    return array;
    return 0;
}
// @lc code=end
