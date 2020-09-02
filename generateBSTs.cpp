#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val):val(val), left(nullptr), right(nullptr){}
        TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
        void printTree(){
            if(!this){
                cout << " NULL ";
                return;
            }
            this->left->printTree();
            cout << this->val << " ";
            this->right->printTree();
        }
};

TreeNode *insertIntoBST(TreeNode *root, int val){
    if(!root){
        return new TreeNode(val);
    }
    if(val < root->val){
        root->left = insertIntoBST(root->left, val);
    }else{
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void printArr(vector<int> arr){
    for(int num: arr){
        cout << num << " ";
    }
    cout << endl;
}

class Solution{
    private:
    void generatePermutation(int index, int n, vector<int>&permutation, vector<int>&arr, vector<vector<int>>& permutations){
        if(index >= n){
            permutations.push_back(permutation);
        }
        for (int i = 1; i <= n;i++){
            if(arr[i] == i){
                permutation[index] = i;
                arr[i] = -1;
                generatePermutation(index + 1, n, permutation, arr, permutations);
                arr[i] = i;
            }
        }
        // printArr(permutation);
    }

    vector<vector<int>> generatePermutations(int n){
        vector<vector<int>> permutations;
        vector<int> permutation(n);
        vector<int> arr(n + 1);
        for (int i = 0; i <= n;i++){
            arr[i] = i;
        }
        generatePermutation(0, n, permutation, arr, permutations);
        return permutations;
    }

    public:
    vector<TreeNode *> generateTrees(int n){
        vector<vector<int>> permutations = generatePermutations(n);
        vector<TreeNode *> roots;
        for (vector<int> permutation : permutations)
        {
            TreeNode *root = NULL;
            // printArr(permutation);
            for (int num : permutation)
            {
                root = insertIntoBST(root, num);
            }
            // root->printTree();
            // cout << endl;
            roots.push_back(root);
        }
        return roots;
    }
};

int main(void){
    int n;
    cin >> n;
    Solution *obj = new Solution();
    vector<TreeNode *> roots = obj->generateTrees(n);
    return 0;
}