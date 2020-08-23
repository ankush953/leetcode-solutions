// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// space O(maxNodesAtAnyLevel)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        int turn = 0;
        // arr[0] => first right then left
        // arr[1] => first left then right
        vector<stack<TreeNode *>> arr(2);
        arr[0].push(root);
        while (arr[0].size() || arr[1].size())
        {
            ans.push_back(vector<int>{});
            while (!arr[turn].empty())
            {
                TreeNode *curr = arr[turn].top();
                arr[turn].pop();
                ans.back().push_back(curr->val);
                if (TreeNode *child = (turn ? curr->right : curr->left))
                {
                    arr[1 - turn].push(child);
                }
                if (TreeNode *child = (!turn ? curr->right : curr->left))
                {
                    arr[1 - turn].push(child);
                }
            }
            turn ^= 1;
        }
        return ans;
    }
};