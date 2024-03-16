/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution
{
public:
    map<int, bool> temp;
    bool result = false;
    int first = 0;
    int second = 0;

    bool def(vector<int> &nums, int x, int &number)
    {
        bool result = false;
        int i = 0;
        int j = nums.size() - 1;

        for (int h = 0; h <= 1; h++)
        {
            if (h == 0)
            {
                for (; i < nums.size(); i++)
                {
                    if (((x >> i) & 1) == 0)
                    {
                        number = number + nums[i];
                        if (i == nums.size() - 1 && first >= second)
                        {
                            result = true;
                        }
                        else
                        {
                            result = def(nums, (x | (1 << i)), second);
                            if (result == false)
                            {
                                result = true;
                            }
                        }
                        break;
                    }
                }
            }
            number = number - nums[i];
            if (h == 1)
            {
                for (; j >= 0; j--)
                {
                    if ((x & (1 << j)) == 0)
                    {
                        number = number + nums[j];
                        if (j == 0 && first >= second)
                        {
                            result = true;
                        }
                        else
                        {
                            result = def(nums, x | (1 << j), second);
                            if (result == false)
                            {
                                result = true;
                            }
                        }
                        break;
                    }
                }
            }
        }

        return result;
    }

    bool predictTheWinner(vector<int> &nums)
    {
        return def(nums, 0, first);
    }
};
// @lc code=end
