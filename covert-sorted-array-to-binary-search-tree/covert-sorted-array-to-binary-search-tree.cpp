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
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        if (start == end) {
            TreeNode *p = new TreeNode(num[start]);
            return p;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        TreeNode *left = sortedArrayToBST(num, start, mid - 1);
        TreeNode *right = sortedArrayToBST(num, mid + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
};