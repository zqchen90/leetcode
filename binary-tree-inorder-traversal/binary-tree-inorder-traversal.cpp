/**
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(root->val);
            return ret;
        }
        vector<int> left;
        vector<int> right;
        if (root->left != NULL) {
            left = inorderTraversal(root->left);
        }
        for (int i = 0; i < left.size(); ++i) {
            ret.push_back(left[i]);
        }
        ret.push_back(root->val);
        if (root->right != NULL) {
            right = inorderTraversal(root->right);
        }
        for (int i = 0; i < right.size(); ++i) {
            ret.push_back(right[i]);
        }
        return ret;
    }
};