// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
private:
    int findCombination(int n, int r){
        long long res = 1;
        int limit = min(r,n-r);
        for(int i=1;i<=limit;i++){
            res *= n;
            res /= i;
            n--;
        }
        return res;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            ans[i] = findCombination(rowIndex,i);
        }
        return ans;
    }
};

