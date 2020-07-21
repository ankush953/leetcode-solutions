// https://leetcode.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<string>> ans;
    void getAllPalindromes(int index, int n, string s, vector<string> v, const vector<vector<bool>> dp)
    {
        if (index == n)
        {
            ans.push_back(v);
        }
        string currString = "";
        for (int j = index; j < n; j++)
        {
            currString += s[j];
            if (dp[index][j])
            {
                v.push_back(currString);
                getAllPalindromes(j + 1, n, s, v, dp);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<string> v;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int i, j;
        for (i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (i = 0; i < n - 1; i++)
        {
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int len = 3; len <= n; len++)
        {
            for (i = 0; i < n - len + 1; i++)
            {
                dp[i][i + len - 1] = (dp[i + 1][i + len - 2] && s[i] == s[i + len - 1]);
            }
        }
        getAllPalindromes(0, n, s, v, dp);
        return ans;
    }
};

int main(void)
{
    string s;
    cin >> s;
    vector<vector<string>> ans = (new Solution())->partition(s);
    for (vector<string> stringArr : ans)
    {
        for (string s : stringArr)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}