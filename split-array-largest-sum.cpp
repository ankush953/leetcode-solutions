// https://leetcode.com/problems/split-array-largest-sum/
// space O(nums.size() * m)
// time O(nums.size() * m)

class Solution
{
    long long findMaxSum(int index, int k, const vector<int> &nums, vector<vector<long long>> &dp)
    {
        if (index == nums.size())
        {
            return (k == 0 ? 0 : INT_MAX);
        }
        if (k == 0)
        {
            return (index == nums.size() ? 0 : INT_MAX);
        }
        if (dp[index][k] != -1)
        {
            return dp[index][k];
        }
        long long ans = INT_MAX, sum = 0;
        for (int i = index; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = min(ans, max(sum, findMaxSum(i + 1, k - 1, nums, dp)));
        }
        return dp[index][k] = ans;
    }

public:
    int splitArray(vector<int> &nums, int m)
    {
        vector<vector<long long>> dp(nums.size() + 1, vector<long long>(m + 1, -1));
        return findMaxSum(0, m, nums, dp);
    }
};