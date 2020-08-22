// https://leetcode.com/problems/squares-of-a-sorted-array/
// Space O(arraySize)
// time O(arraySize)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j = A.size()-1;
        vector<int>ans(A.size());
        int k = j;
        while(i<=j){
            if(A[i]*A[i] > A[j]*A[j]){
                ans[k--] = A[i]*A[i];
                i++;
            }else{
                ans[k--] = A[j]*A[j];
                j--;
            }
        }
        return ans;
    }
};
