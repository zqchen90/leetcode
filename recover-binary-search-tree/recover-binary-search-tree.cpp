#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

void detect(TreeNode *prev, TreeNode *cur, TreeNode **swap1, TreeNode **swap2) {
    if (prev != NULL && prev->val > cur->val) {
        if (*swap1 == NULL) {
            *swap1 = prev;
        }
        *swap2 = cur;
    }
}

void recoverTree(TreeNode *root) {
    TreeNode *cur = root;
    TreeNode *prev = NULL;
    TreeNode *swap1 = NULL;
    TreeNode *swap2 = NULL;
    
    while (cur != NULL) {
        print_TreeNode(cur, prev);
        if (cur->left == NULL) {
            detect(prev, cur, &swap1, &swap2);
            prev = cur;
            cur = cur->right;
        } else {
            TreeNode *node = cur->left;
            while (node->right != NULL && node->right != cur) {
                node = node->right;           
            }
            //print_TreeNode(cur, prev);
            if (node->right == NULL) {
                node->right = cur;
                cur = cur->left;
            } else {
                detect(prev, cur, &swap1, &swap2);
                node->right = NULL;
                prev = cur;
                cur = cur->right;
            }
        }
    }
    int tmp = swap1->val;
    swap1->val = swap2->val;
    swap2->val = tmp; 
}


int main() {
    TreeNode root(0);
    TreeNode left(1);
    root.left = &left;
    recoverTree(&root);

    cout<<endl;

    TreeNode root2(2);
    TreeNode right(1);
    root2.right = &right;
    recoverTree(&root2);
    return 0;
}

