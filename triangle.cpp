// https://leetcode.com/problems/triangle/
// space O(1) manipulating the given matrix
// time O(numberOfElements)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                int temp = INT_MAX;
                if(i > 0 && j > 0){
                    temp = triangle[i][j] + triangle[i-1][j-1];
                }
                if(j < triangle[i-1].size()){
                   temp = min(temp, triangle[i][j] + triangle[i-1][j]);
                }
                 triangle[i][j] = temp;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<triangle.back().size();i++){
            ans = min(ans, triangle.back()[i]);
        }
        return ans;
    }
};
