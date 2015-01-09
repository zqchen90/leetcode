#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void detect(TreeNode *prev, TreeNode *cur, TreeNode **swap1, TreeNode **swap2) {
    if (NULL != prev && prev->val > cur->val) {
        if (*swap1 == NULL) {
            *swap1 = prev;
        }
        *swap2 = cur;
    }
}

void print_TreeNode(TreeNode *cur, TreeNode *prev) {
    if (NULL == prev) {
        cout<<"[NULL";
    } else {
        cout<<"["<<prev->val;
    }
    if (NULL == cur) {
        cout<<", NULL]";
    } else {
        cout<<", "<<cur->val<<"]";
    }
    cout<<endl;
}

void recoverTree(TreeNode *root) {
    TreeNode *cur = root;
    TreeNode *prev = NULL;
    TreeNode *swap1 = NULL;
    TreeNode *swap2 = NULL;
    
    while (cur != NULL) {
        print_TreeNode(cur, prev);
        if (cur->left == NULL) {
            detect(cur, prev, &swap1, &swap2);
            prev = cur;
            cur = cur->right;
        } else {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur) {
                prev = prev->right;           
            }
            //print_TreeNode(cur, prev);
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                detect(prev, cur, &swap1, &swap2);
                prev->right = NULL;
                prev = cur;
                cur = cur->right;
            }
        }
    }
    int tmp = swap1->val;
    swap1->val = swap2->val;
    
}


int main() {
    TreeNode root(0);
    TreeNode left(1);
    root.left = &left;
    recoverTree(&root);

    TreeNode root2(0);
    TreeNode right(1);
    root2.right = &right;
    recoverTree(&root2);
    return 0;
}

