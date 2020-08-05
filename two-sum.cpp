// https://leetcode.com/problems/two-sum/
// space O(n)
// time O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            auto ptr = mp.find(target-nums[i]);
            if(ptr==mp.end())
                mp[nums[i]] = i;
            else{
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
