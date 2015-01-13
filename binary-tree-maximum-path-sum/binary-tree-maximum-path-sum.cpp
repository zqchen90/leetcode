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
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if (l > 0) {
            sum += l;
        }
        if (r > 0) {
            sum += r;
        }
        max_sum = max(max_sum, sum);
        int max_lr = max(l, r);
        if (max_lr > 0) {
            return root->val + max_lr;
        } else {
            return root->val;
        }
		// return root -> left or root -> right
		// can't return both because there is no such path: left <- root -> right
    }
};