// https://leetcode.com/problems/longest-well-performing-interval/
// space O(n)
// time O(n)

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        unordered_map<int, int> seenBefore;
        int sum = 0, ans = 0;
        for (int i = 0; i < hours.size(); i++)
        {
            sum += (hours[i] > 8 ? 1 : -1);
            if (sum > 0)
            {
                ans = i + 1;
            }
            else
            {
                if (seenBefore.find(sum - 1) != seenBefore.end())
                {
                    ans = max(ans, i - seenBefore[sum - 1]);
                }
                else if (seenBefore.find(sum) == seenBefore.end())
                {
                    seenBefore[sum] = i;
                }
            }
        }
        return ans;
    }
};