// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// space O(1)
// time O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, preCount = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int count = 0;
            while(i < n && nums[i] == 1){
                count++;
                i++;
            }
            ans = max(ans, preCount + count);
            preCount = count;
        }
        if(ans == n){
            return n-1;
        }
        return ans;
    }
};
