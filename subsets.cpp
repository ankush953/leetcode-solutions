// https://leetcode.com/problems/subsets/
// space O(n*2^n)
// time O(2^n)

class Solution {
    
    vector<vector<int>>ans;
    void fun(int index,int size, int total, vector<int>&curr,const vector<int>&nums){
        if(index == total){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        fun(index+1,size+1,total,curr,nums);
        curr.pop_back();
        fun(index+1,size,total,curr,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        int n = nums.size();
        fun(0,0,n,curr,nums);
        return ans;
    }
};
