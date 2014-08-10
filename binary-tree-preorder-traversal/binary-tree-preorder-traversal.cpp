#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> ret;
    if (root == NULL) {
        return ret;
    }
	list<TreeNode *> waitinglist;

	waitinglist.push_front(root);
	TreeNode *cur;
	while (waitinglist.size() > 0) {
        cur = waitinglist.back();
		waitinglist.pop_back();
		ret.push_back(cur->val);
		if (cur->right != NULL) {
			waitinglist.push_back(cur->right);
		}
		if (cur->left != NULL) {
			waitinglist.push_back(cur->left);
		}
	}

	return ret;
}

int main() {
	TreeNode tn2 = TreeNode(2); 
    TreeNode tn3 = TreeNode(3);
    TreeNode tn1 = TreeNode(1);
    tn1.right = &tn2;
    tn2.left = &tn3;

    vector<int> ret;
    ret = preorderTraversal(&tn1);
    vector<int>::iterator iter;
    for (iter = ret.begin(); iter != ret.end(); ++iter) {
        cout<<*iter<<endl;
    }
}