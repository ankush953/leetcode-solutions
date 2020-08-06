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
class Solution {
    TreeNode *buildTree(int &index, int low, int high, vector<int>&preorder, vector<int>&inorder, unordered_map<int,int>&mp){
        if(low > high){
            return NULL;
        }
        int currIdx = index;
        TreeNode *root = new TreeNode(preorder[index]);
        index++;
        root->left = buildTree(index, low, mp[preorder[currIdx]] - 1, preorder, inorder, mp);
        if(!root->left) index--;
        index++;
        root->right = buildTree(index, mp[preorder[currIdx]] + 1, high, preorder, inorder, mp);
        if(!root->right) index--;
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n = preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int index = 0;
        return buildTree(index, 0, n-1, preorder, inorder, mp);
    }
};
