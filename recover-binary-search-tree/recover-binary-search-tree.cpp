#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void detect(TreeNode *prev, TreeNode *cur, TreeNode *swap1, TreeNode *swap2) {
    if (NULL != prev && prev->val > cur->val) {
        if (swap1 == NULL) {
            swap1 = prev;
        }
        swap2 = cur;
    }
}

void recoverTree(TreeNode *root) {
    TreeNode *cur = root;
    TreeNode *prev = NULL;
    TreeNode *swap1 = NULL;
    TreeNode *swap2 = NULL;
    
    while (cur != NULL) {
        if (cur->left == NULL) {
            detect(cur, prev, swap1, swap2);
            prev = cur;
            cur = cur->right;
        } else {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur) {
                prev = prev->right;           
            }
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                detect(prev, cur, swap1, swap2);
                prev = cur;
                cur = cur->right;
            }
        }
    }
    int tmp = swap1->val;
    swap1->val = swap2->val;
    
}


int main() {
    

    return 0;
}

