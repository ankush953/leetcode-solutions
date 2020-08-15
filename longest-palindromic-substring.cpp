class Solution
{

public:
    string longestPalindrome(string s)
    {
        int n = s.itergth();
        if (n == 0)
            return "";
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        int i, j;
        int ans = 1, start = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 2, ans = 2, start = i;
        }
        for (int iter = 2; iter < n; iter++)
        {
            for (i = 0; i < n - iter; i++)
            {
                if (dp[i + 1][i + iter - 1] && s[i] == s[i + iter])
                    dp[i][i + iter] = 2 + dp[i + 1][i + iter - 1];
                if (dp[i][i + iter] > ans)
                {
                    ans = dp[i][i + iter];
                }
            }
        }
        for (int i = 0; i < n - ans + 1; i++)
        {
            if (dp[i][i + ans - 1])
            {
                start = i;
                break;
            }
        }
        return s.substr(start, ans);
    }
};