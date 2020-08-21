// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// space O(1)
// time O(log N)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = 0;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(nums[mid] > nums[n-1]){
                low = mid+1;
            }else{
                ans = nums[mid];
                high = mid-1;
            }
        }
        return ans;
    }
};
