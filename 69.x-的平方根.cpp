/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int backstrack(int &x, int left, int right)
    {
        cout<<left<<endl;
        if(  left || ((left + right) / 2 + 1) * ((left + right) / 2 + 1))
        {
            return (left + right) / 2;
        }

        if(((left + right) / 2) * ((left + right) / 2) <= x && ((left + right) / 2 + 1) * ((left + right) / 2 + 1) > x)
        {
            return (left + right) / 2;
        }
        if(left * left <= x && ((left + right) / 2) * ((left + right) / 2) > x)
        {
            return backstrack(x, left, (left + right) / 2);
        }

        if(((left + right) / 2) * ((left + right) / 2) <= x && right * right > x)
        {
            return backstrack(x, (left + right) / 2, right);
        }

    }

    int mySqrt(int x)
    {
        if(x <= 1)
        {
            return 0;
        }

        return backstrack(x, 1, x);
    }
};
// @lc code=end
