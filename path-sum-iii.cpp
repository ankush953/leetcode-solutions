// https://leetcode.com/problems/path-sum-iii/
// space O(height)
// time O(numberOfNodes)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

public:
    int pathSum(TreeNode *root, int sum, vector<int> curr = {})
    {
        if (!root)
            return 0;
        int ans = 0;
        int temp = sum;
        curr.push_back(root->val);
        for (int i = curr.size() - 1; i > -1; i--)
        {
            temp -= curr[i];
            ans += (temp == 0);
        }
        ans += pathSum(root->left, sum, curr);
        ans += pathSum(root->right, sum, curr);
        curr.pop_back();
        return ans;
    }
};