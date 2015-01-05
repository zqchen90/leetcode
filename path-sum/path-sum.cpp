/**
 * Given the below binary tree and sum and return a ROOT-TO-LEAF path which sum is the given one
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root) {
            return false;
        }
        if (root->val == sum && NULL == root->left && NULL == root->right) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};