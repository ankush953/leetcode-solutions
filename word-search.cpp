// https://leetcode.com/problems/word-search/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, 1, -1};

public:
    char ch;
    bool finish;
    Trie *children[125];

    Trie(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 125; i++)
        {
            this->children[i] = NULL;
        }
        this->finish = false;
    }

    void insert(Trie *root, string currWord)
    {
        for (int i = 0; i < currWord.size(); i++)
        {
            if (!root->children[currWord[i]])
            {
                root->children[currWord[i]] = new Trie(currWord[i]);
            }
            root = root->children[currWord[i]];
        }
        root->finish = true;
    }

    bool checkIfPresent(int r, int c, int m, int n, int index, string word, vector<vector<char>> &board)
    {
        if (r < 0 || c < 0 || r >= m || c >= n || !this)
        {
            return false;
        }
        if (board[r][c] != this->ch)
        {
            return false;
        }
        board[r][c] = '$';
        if (this->finish)
        {
            return true;
        }
        bool found = false;
        for (int j = 0; j < 4; j++)
        {
            found |= this->children[word[index + 1]]->checkIfPresent(r + row[j], c + col[j], m, n, index + 1, word, board);
            if (found)
            {
                return true;
            }
        }
        board[r][c] = this->ch;
        return found;
    }
};

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        if (m == 0)
            return 0;
        int n = board[0].size();
        if (n == 0)
            return 0;
        Trie *root = new Trie('\0');
        root->insert(root, word);
        int i, j, k;
        bool exist = false;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (root->children[board[i][j]])
                {
                    exist |= root->children[board[i][j]]->checkIfPresent(i, j, m, n, 0, word, board);
                    if (exist)
                    {
                        return true;
                    }
                }
            }
        }
        return exist;
    }
};

int main(void)
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    cout << (new Solution())->exist(board, word);
    return 0;
}
