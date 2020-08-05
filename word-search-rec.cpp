// https://leetcode.com/problems/word-search/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int i, int j, int pos, int m, int n, string word, vector<vector<bool>> &visited, vector<vector<char>> &board)
    {
        if (pos == word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        if (visited[i][j])
            return false;
        bool result = word[pos] == board[i][j];
        if (!result)
            return false;
        int x[] = {0, 0, -1, 1};
        int y[] = {-1, 1, 0, 0};
        visited[i][j] = true;
        int d;
        for (d = 0; d < 4; d++)
        {
            if (result && dfs(i + x[d], j + y[d], pos + 1, m, n, word, visited, board))
            {
                break;
            }
        }
        visited[i][j] = false;
        return !(d == 4);
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        if (m == 0)
            return 0;
        int n = board[0].size();
        if (n == 0)
            return 0;
        if (word.size() == 0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool result = dfs(i, j, 0, m, n, word, visited, board);
                if (result)
                    return true;
            }
        }
        return false;
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
