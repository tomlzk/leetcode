/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution
{
public:
    // 进行修改
    int change(vector<int> &nums, int left, int right)
    {
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (nums[j] <= nums[right])
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i++], nums[right]);
        return i;
    }

    // 得到标准值，并且按照标准值进行排序
    int getmid(vector<int> &nums, int left, int right)
    {
        int number = (rand() % (right - left + 1)) + left;
        swap(nums[number], nums[right]);
        return change(nums, left, right);
    }

    // 使用快速排序的方法对数组进行排序
    void quicksort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = getmid(nums, left, right);
        quicksort(nums, left, mid - 1);
        quicksort(nums, mid + 1, right);
    }

    void wiggleSort(vector<int> &nums)
    {
        vector<int> result;
        srand((unsigned)time(NULL));
        quicksort(nums, 0, nums.size() - 1);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << endl;
        }
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            result.push_back(nums[i]);
            i++;
            if (i <= j)
            {
                result.push_back(nums[j]);
                j--;
            }
        }
        nums = result;
    }
};
// @lc code=end
