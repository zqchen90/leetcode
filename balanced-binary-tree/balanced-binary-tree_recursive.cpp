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
    int getHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return right > left? right + 1 : left + 1 ;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if ((left == right || left - right == 1 || left - right == -1) && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};