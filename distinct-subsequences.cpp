// https://leetcode.com/problems/distinct-subsequences/
// space O(m*n)
// time O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getAnswer(int i, string a, int j, string b, vector<vector<int>>&dp) {
        if (j == b.size()) {
            return 1;
        }
        if (i == a.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int exculding = getAnswer(i+1, a, j, b, dp);
        int including = 0;
        if (a[i] == b[j]) {
            including = getAnswer(i+1, a, j+1, b, dp);
        }
        return dp[i][j] = exculding+including;
    }
public:
    int getDistinctSubsequences(string a, string b) {
        int m = a.size();
        int n = b.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return getAnswer(0, a, 0, b, dp);
    }
};

int main(void) {
    string a, b;
    cin >> a >> b;
    cout << (new Solution())->getDistinctSubsequences(a, b);
    return 0;
}