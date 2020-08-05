// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *fun(vector<int> &inorder, vector<int> &postorder, int s, int e, int &idx, unordered_map<int, int> &pos)
    {
        if (s > e)
        {
            return NULL;
        }
        TreeNode *currNode = new TreeNode(postorder[idx], NULL, NULL);
        idx--;
        currNode->right = fun(inorder, postorder, pos[postorder[idx]] + 1, e, idx, pos);
        if (!currNode->right)
        {
            idx++;
        }
        idx--;
        currNode->left = fun(inorder, postorder, s, pos[postorder[idx]] - 1, idx, pos);
        if (!currNode->left)
        {
            idx++;
        }
        return currNode;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int idx = inorder.size() - 1;
        unordered_map<int, int> pos;
        for (int i = 0; i < inorder.size(); i++)
        {
            pos[inorder[i]] = i;
        }
        return fun(inorder, postorder, 0, inorder.size() - 1, idx, pos);
    }
};

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = (new Solution())->buildTree(inorder, postorder);
    return 0;
}