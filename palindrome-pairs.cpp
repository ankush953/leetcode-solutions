// https://leetcode.com/problems/palindrome-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string str)
    {
        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> ans;
        unordered_map<string, int> inWords;
        map<pair<int, int>, bool> alreadyCounted;
        for (int i = 0; i < words.size(); i++)
        {
            inWords[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++)
        {
            string candidateString = "";
            for (int j = 0; j < words[i].size() + 1; j++)
            {
                // cout << words[i] << " " << candidateString << endl;
                if (inWords.find(candidateString) != inWords.end() && alreadyCounted.find({i, inWords[candidateString]}) == alreadyCounted.end() && i != inWords[candidateString] && isPalindrome(words[i] + candidateString))
                {
                    alreadyCounted[{i, inWords[candidateString]}] = true;
                    ans.push_back({i, inWords[candidateString]});
                    if (alreadyCounted.find({inWords[candidateString], i}) == alreadyCounted.end() && isPalindrome(candidateString + words[i]))
                    {
                        alreadyCounted[{inWords[candidateString], i}] = true;
                        ans.push_back({inWords[candidateString], i});
                    }
                }
                candidateString = words[i][j] + candidateString;
            }
            candidateString = "";
            for (int j = words[i].size() - 1; j > -1; j--)
            {
                candidateString += words[i][j];
                // cout << words[i] << " " << candidateString << endl;
                if (inWords.find(candidateString) != inWords.end() && alreadyCounted.find({inWords[candidateString], i}) == alreadyCounted.end() && i != inWords[candidateString] && isPalindrome(candidateString + words[i]))
                {
                    alreadyCounted[{inWords[candidateString], i}] = true;
                    ans.push_back({inWords[candidateString], i});
                    if (alreadyCounted.find({i, inWords[candidateString]}) == alreadyCounted.end() && isPalindrome(words[i] + candidateString))
                    {
                        alreadyCounted[{i, inWords[candidateString]}] = true;
                        ans.push_back({i, inWords[candidateString]});
                    }
                }
            }
        }
        return ans;
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    vector<vector<int>> ans = (new Solution())->palindromePairs(words);
    for (vector<int> currPair : ans)
    {
        cout << currPair[0] << " " << currPair[1] << endl;
    }
    return 0;
}