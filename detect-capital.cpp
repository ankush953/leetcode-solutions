// https://leetcode.com/problems/detect-capital/
// space O(1)
// time O(n)

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        if (!n)
        {
            return true;
        }
        int c = word[0] > 64 && word[0] < 91;
        int later = 0;
        for (int i = 1; i < n; i++)
        {
            later += (word[i] > 64 && word[i] < 91);
        }
        return (c + later == n) || !later;
    }
};