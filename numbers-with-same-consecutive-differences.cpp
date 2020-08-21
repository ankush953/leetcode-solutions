// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// space O(2^N * avgLen)
// time O(2^N)

class Solution {
    void fun(string curr, int N, int K, vector<int>&ans){
        if(curr.size() == N){
            ans.push_back(stoi(curr));
            return;
        }
        if(curr.back() + K < 58)
            fun(curr+(char)(K + curr.back()), N, K, ans);
        if(K && curr.back() - K > 47)
            fun(curr+(char)(curr.back() - K), N, K, ans);
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>ans;
        for(int i = (N > 1);i<10;i++){
            fun(to_string(i),N,K,ans);
        }
        return ans;
    }
};
