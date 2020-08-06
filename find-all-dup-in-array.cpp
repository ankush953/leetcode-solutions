// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// space O(1)
// time O(n)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};