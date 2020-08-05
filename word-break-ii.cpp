// https://leetcode.com/problems/word-break-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void generateWords(int index, string s, int n, unordered_map<string, bool> &present, bool possible[], string curr, vector<string> &words)
    {
        if (index >= n)
        {
            curr.pop_back();
            words.push_back(curr);
        }
        string temp = "";
        for (int i = index; i < n; i++)
        {
            temp += s[i];
            if (possible[i + 1] && present[temp])
            {
                generateWords(i + 1, s, n, present, possible, curr + temp + " ", words);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
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
                if (possible[j + 1] && present[temp])
                {
                    possible[i] = true;
                    break;
                }
            }
        }
        vector<string> words;
        generateWords(0, s, n, present, possible, "", words);
        return words;
    }
};
int main()
{
    string s;
    vector<string> wordDict;
    vector<string> words = (new Solution())->wordBreak(s, wordDict);
    for (string word : words)
    {
        cout << word << " ";
    }
    return 0;
}
