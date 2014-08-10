/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <list>

class Solution {
public:
    void flatten(TreeNode *root) {
    if (root == NULL) {
        return;
    }
	list<TreeNode *> waitinglist;
	vector<TreeNode *>preorderlist;

	waitinglist.push_front(root);
	TreeNode *cur;
	while (waitinglist.size() > 0) {
        cur = waitinglist.back();
		waitinglist.pop_back();
		preorderlist.push_back(cur);
		if (cur->right != NULL) {
			waitinglist.push_back(cur->right);
		}
		if (cur->left != NULL) {
			waitinglist.push_back(cur->left);
		}
	}
	
    for (int i = 0; i < preorderlist.size() - 1; ++i) {
        preorderlist[i]->left = NULL;
        preorderlist[i]->right = preorderlist[i + 1];
    }


    }
};