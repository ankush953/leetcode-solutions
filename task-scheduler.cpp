// https://leetcode.com/problems/task-scheduler/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int freq[26] = {0};
        for (char letter : tasks)
        {
            freq[letter - 'A']++;
        }
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i])
            {
                pq.push(freq[i]);
            }
        }
        n++;
        int lastBatch = n;
        int ans = 0;
        while (!pq.empty())
        {
            int extracted = 0;
            vector<int> v;
            while (!pq.empty() && extracted < n)
            {
                v.push_back(pq.top() - 1);
                pq.pop();
                extracted++;
            }
            lastBatch = extracted;
            ans += n;
            for (int rem : v)
            {
                if (rem)
                {
                    pq.push(rem);
                }
            }
        }
        return ans - (n - lastBatch);
    }
};

int main(void)
{
    vector<char> tasks = {};
    int n = 2;
    cout << (new Solution())->leastInterval(tasks, n);
    return 0;
}