class Solution
{
public:
    bool f(int i, int j, int one, int curr, vector<int> &nums)
    {
        if (i > j)
        {
            return one >= 0;
        }
        int ans = 0;
        if (curr)
        {

            ans = f(i + 1, j, one + nums[i], 0, nums) || f(i, j - 1, one + nums[j], 0, nums);
        }
        else
        {

            ans = f(i + 1, j, one - nums[i], 1, nums) && f(i, j - 1, one - nums[j], 1, nums);
        }

        return ans;
    }
    bool predictTheWinner(vector<int> &nums)
    {
        return f(0, nums.size() - 1, 0, 1, nums);
    }
};