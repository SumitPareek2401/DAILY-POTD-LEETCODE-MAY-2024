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
public:
    int dfs(TreeNode * root, int& sum) {
        if(root == NULL) return 0;
        int l = dfs(root -> left, sum);
        int r = dfs(root -> right, sum);
        sum += abs(l) + abs(r);
        return l + r + root -> val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};
