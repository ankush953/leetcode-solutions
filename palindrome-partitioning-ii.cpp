// https://leetcode.com/problems/palindrome-partitioning-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int i, j;
        int n = s.length();
        int cut[n + 1];
        for (i = 0; i <= n; i++)
        {
            cut[i] = i - 1;
        }
        for (i = 0; i < n; i++)
        {
            // odd length palindrome
            for (j = 0; i - j > -1 && i + j < n && s[i - j] == s[i + j]; j++)
            {
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
            }
            // even length palindrome
            for (j = 1; i - j + 1 > -1 && i + j < n && s[i - j + 1] == s[i + j]; j++)
            {
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
            }
        }
        return cut[n];
    }
};

int main(void)
{
    string s;
    cin >> s;
    cout << (new Solution())->minCut(s);
    return 0;
}