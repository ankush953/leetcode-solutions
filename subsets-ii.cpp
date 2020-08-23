// https://leetcode.com/problems/subsets-ii/
// space O(2^n * avgSize)
// time O(2^n)

class Solution{
public: 
	vector<vector<int>> subsetsWithDup(vector<int>&nums){
		vector<vector<int>>ans({{}});
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for(int i=0;i<n;){
            int count = 0;
            while(i+count < n && nums[i] == nums[count+i]) count++;
            int prevSize = ans.size();
            for(int preIndex=0;preIndex<prevSize;preIndex++){
                vector<int>currAns = ans[preIndex];
                for(int j=0;j<count;j++){
                    currAns.push_back(nums[i]);
                    ans.push_back(currAns);
                }
            }
            i += count;
        }
		return ans;
	}
};