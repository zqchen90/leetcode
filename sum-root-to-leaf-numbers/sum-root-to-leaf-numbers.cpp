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

int sumNumbers(TreeNode *root) {
    int sum = 0;
    if (root == NULL) {
        return 0;
    }
	list<TreeNode *> waitinglist;

	waitinglist.push_front(root);
	TreeNode *cur;
    while (waitinglist.size() > 0) {
        cur = waitinglist.back();
        waitinglist.pop_back();
        if (cur->right == NULL && cur->left == NULL) {   // find a path
            sum += cur->val;
        }
        if (cur->right != NULL) {
            cur->right->val += cur->val * 10;
			waitinglist.push_back(cur->right);
		}
        if (cur->left != NULL) {
            cur->left->val += cur->val * 10;
			waitinglist.push_back(cur->left);
		}

    }
    return sum;  
}

int main() {
	TreeNode tn2 = TreeNode(2); 
    TreeNode tn3 = TreeNode(3);
    TreeNode tn1 = TreeNode(1);
    tn1.right = &tn2;
    tn1.left = &tn3;

    int ret = sumNumbers(&tn1);
    cout<<ret<<endl;
}