// https://leetcode.com/problems/unique-binary-search-trees-ii/
// space O(n!)
// time O(n!)

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
class Solution{
    private:
    vector<TreeNode *> generateTree(int start, int end){
        vector<TreeNode *> roots;
        if(start > end){
            roots.push_back(nullptr);
        }
        for (int i = start; i <= end;i++){
            vector<TreeNode *> leftChildren = generateTree(start, i - 1);
            vector<TreeNode *> rightChildren = generateTree(i + 1, end);
            for(TreeNode *leftChild: leftChildren){
                for(TreeNode *rightChild: rightChildren){
                    TreeNode *root = new TreeNode(i, leftChild, rightChild);
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }

    public:
    vector<TreeNode *> generateTrees(int n){
        if(!n) return vector<TreeNode *>{};
        return generateTree(1, n);
    }
};
