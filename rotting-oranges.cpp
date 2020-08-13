// https://leetcode.com/problems/rotting-oranges/
// space O(m*n)
// time O(m*n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>>q;
        int m = grid.size();
        int n = grid[0].size();
        bool visited[m][n];
        // memset(visited,false,sizeof visited);
        int i, j;
        int count =0;
        for (i=0;i<m;i++) {
            for (j=0;j<n;j++) {
                visited[i][j] =0;
                if (grid[i][j]==2) {
                    q.push({ { i, j }, 0 });
                    visited[i][j] = true;
                }                
else if (grid[i][j]==1) {
                    count++;
                }
            }
        }
        int ans = 0;
        int x[] ={ -1, 1, 0, 0 };
        int y[] ={ 0, 0, -1, 1 };
        // cout << count << endl;
        while (!q.empty()) {
            pair<pair<int, int>, int>temp = q.front();
            pair<int, int>curr = temp.first;
            ans = temp.second;
            q.pop();
            for (i=0;i<4;i++) {
                int cx = curr.first+x[i];
                int cy = curr.second+y[i];
                if (cx>-1 && cx < m && cy > -1 && cy < n && !visited[cx][cy] && grid[cx][cy] == 1) {
                    count--;
                    visited[cx][cy] = 1;
                    q.push({ { cx, cy }, temp.second+1 });
                }
            }
        }
        return count == 0?ans:-1;
    }
};