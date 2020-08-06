// https://leetcode.com/problems/minimum-window-substring/
// space O(60)
// time O(length(s))

class Solution
{
private:
    bool isEqual(int *a, int *b)
    {
        for (int i = 0; i < 60; i++)
        {
            if (a[i] < b[i])
                return 0;
        }
        return 1;
    }

public:
    string minWindow(string s, string t)
    {
        int freq1[60] = {0}, freq2[60] = {0};
        int i, j;
        int m = s.length(), n = t.length();
        string ans = "";
        for (i = 0; i < n; i++)
            freq2[t[i] - 65]++;
        i = 0;
        j = 0;
        int curr = INT_MAX;
        while (i < m && j < m)
        {
            if (j - i >= n && isEqual(freq1, freq2))
            {
                if (j - i < curr)
                {
                    curr = j - i;
                    ans = s.substr(i, j - i);
                }
                freq1[s[i] - 65]--;
                i++;
            }
            else
                freq1[s[j] - 65]++, j++;
        }
        while (isEqual(freq1, freq2))
        {
            if (j - i >= n && j - i < curr)
            {
                curr = j - i;
                ans = s.substr(i, j - i);
            }
            freq1[s[i] - 65]--;
            i++;
        }
        return ans;
    }
};