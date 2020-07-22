// https://leetcode.com/problems/word-search-ii/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, 1, -1};

public:
    char ch;
    bool finish;
    string word;
    Trie *children[26];

    Trie(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->finish = false;
    }

    void insert(Trie *root, string currWord)
    {
        for (int i = 0; i < currWord.size(); i++)
        {
            if (!root->children[currWord[i] - 97])
            {
                root->children[currWord[i] - 97] = new Trie(currWord[i]);
            }
            root = root->children[currWord[i] - 97];
        }
        root->finish = true;
        root->word = currWord;
    }

    void checkIfPresent(int r, int c, int m, int n, vector<string> &ans, vector<vector<char>> &board)
    {
        if (r < 0 || c < 0 || r >= m || c >= n)
        {
            return;
        }
        if (board[r][c] != this->ch)
        {
            return;
        }

        board[r][c] = '$';
        if (this->finish)
        {
            ans.push_back(this->word);
            this->finish = false;
        }
        for (int i = 0; i < 26; i++)
        {
            if (this->children[i])
            {
                for (int j = 0; j < 4; j++)
                {
                    this->children[i]->checkIfPresent(r + row[j], c + col[j], m, n, ans, board);
                }
            }
        }
        board[r][c] = this->ch;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        Trie *root = new Trie('\0');
        for (string word : words)
        {
            root->insert(root, word);
        }
        int i, j;
        int m = board.size(), n = board[0].size();
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (root->children[board[i][j] - 97])
                {
                    root->children[board[i][j] - 97]->checkIfPresent(i, j, m, n, ans, board);
                }
            }
        }
        return ans;
    }
};

int main(void)
{
    int m, n, i, j;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    int arrSize;
    cin >> arrSize;
    vector<string> words(arrSize);
    for (i = 0; i < arrSize; i++)
    {
        cin >> words[i];
    }
    vector<string> ans = (new Solution())->findWords(board, words);
    for (string word : ans)
    {
        cout << word << " ";
    }
    return 0;
}