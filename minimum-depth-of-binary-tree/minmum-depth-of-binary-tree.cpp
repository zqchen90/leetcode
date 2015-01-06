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
    int minDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        // a leaf
        if (NULL == root->left && NULL == root->right) {
            return 1;
        }
        if (NULL == root->left) {
            return 1 + minDepth(root->right);
        }
        if (NULL == root->right) {
            return 1 + minDepth(root->left);
        }
        int min_depth_left = minDepth(root->left);
        int min_depth_right = minDepth(root->right);
        int min_depth = min_depth_left < min_depth_right ? min_depth_left : min_depth_right;
        return min_depth + 1;
    }
};