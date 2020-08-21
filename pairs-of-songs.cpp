// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// space O(60)
// time O(n)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int freq[60]={0};
        int ans = 0;
        for(int sec: time){
            freq[sec%60]++;
        }
        for(int i=1;i<30;i++){
            ans += (freq[i]*freq[60-i]);
        }
        ans += (freq[0]*(freq[0]-1)/2);
        ans += (freq[30]*(freq[30]-1)/2);
        return ans;
    }
};
