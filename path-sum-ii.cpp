// https://leetcode.com/problems/path-sum-ii/
// space O(numberOfPaths * averageSizeOfEachPath)
// time O(V)

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
    void findRoute(TreeNode *root, int sum, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right && root->val == sum)
        {
            curr.push_back(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        findRoute(root->left, sum - root->val, curr, ans);
        findRoute(root->right, sum - root->val, curr, ans);
        curr.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        findRoute(root, sum, curr, ans);
        return ans;
    }
};