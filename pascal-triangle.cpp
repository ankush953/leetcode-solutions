// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans = {{1}};
        if(numRows==0){
            return {};
        }
        for(int i=1;i<numRows;i++){
            ans.push_back(vector<int>(i+1));
            for(int j=0;j<=i;j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        return ans;
    }
};
