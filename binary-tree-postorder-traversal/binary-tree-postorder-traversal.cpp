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
    struct TreeNodeFlag {
        bool flag;
        TreeNode *node;
        TreeNodeFlag(TreeNode *n) : node(n), flag(false) {}
    };
    
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNodeFlag> waiting;
        vector<int> ret;
        if (NULL == root) {
            return ret;
        }
        waiting.push(TreeNodeFlag(root));
        TreeNodeFlag *cur;
        while (waiting.size() != 0) {
            cur = &waiting.top();
            if (cur->flag) {
                ret.push_back(cur->node->val);
                waiting.pop();
            } else {
                if (NULL != cur->node->right) {
                    waiting.push(TreeNodeFlag(cur->node->right));
                }
                if (NULL != cur->node->left) {
                    waiting.push(TreeNodeFlag(cur->node->left));
                }
                cur->flag = true;
            }
        }
        return ret;
    }
};