// https://leetcode.com/problems/get-the-maximum-score/

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        long long s1 = 0, s2 = 0;
        const int inf = 1000000007;
        while(i<n && j < m){
            if(nums1[i] == nums2[j]){
                s1 = s2 = max(s1,s2);
            }
            if(nums1[i] < nums2[j]){
                s1 += nums1[i++];
            }else{
                s2 += nums2[j++];
            }
        }
        while(i<n){
            s1 += nums1[i++];
        }
        while(j<m){
            s2 += nums2[j++];
        }
        return max(s1,s2)%inf;
    }
};
