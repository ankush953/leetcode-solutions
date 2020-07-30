// https://leetcode.com/problems/word-break/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        bool possible[n + 1];
        memset(possible, 0, sizeof possible);
        possible[n] = true;
        unordered_map<string, bool> present;
        for (string word : wordDict)
        {
            present[word] = true;
        }
        for (int i = n - 1; i > -1; i--)
        {
            string temp = "";
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (present[temp] && possible[j + 1])
                {
                    possible[i] = true;
                    break;
                }
            }
        }
        return possible[0];
    }
};

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaab", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    cout << (new Solution())->wordBreak(s, wordDict);
    return 0;
}