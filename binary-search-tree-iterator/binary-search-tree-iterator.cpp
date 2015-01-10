#include <iostream>
#include <stack>
#include "TreeNode.h"

using namespace std;

class BSTIterator {
    public:
        BSTIterator (TreeNode *root) {
            if (NULL != root) {
                TreeNode *p = root;
                while (NULL != p) {
                    s.push(p);
                    p = p->left;
                }
            }
        }

        bool hasNext() {
            return !s.empty();
        }

        int next() {
            TreeNode *p = s.top();
            s.pop();
            TreeNode *pr = p->right;
            while (NULL != pr) {
                s.push(pr);
                pr = pr->left;
            }
            return p->val;
        }
    private:
        stack<TreeNode *> s;
};


int main() {
    

    return 0;
}

