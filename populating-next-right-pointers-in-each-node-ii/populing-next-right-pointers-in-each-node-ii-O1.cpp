#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode * left, *right, *next;
};

void connect(TreeLinkNode *root) {
    TreeLinkNode *cur = root;
    while (cur != NULL) {
        TreeLinkNode *prev = NULL;
        TreeLinkNode *next = NULL;
        for (; cur != NULL; cur = cur->next) {
            if (cur->left != NULL) {
                if (prev != NULL) {
                    prev->next = cur->left;
                }
                prev = cur->left;
                if (next == NULL) {
                    next = cur->left;
                }
            }
            if (cur->right != NULL) {
                if (prev != NULL) {
                    prev->next = cur->right;
                }
                prev = cur->right;
                if (next == NULL) {
                    next = cur->right;
                }
            }
        }
        cur = next;
    }
}

int main() {
    

    return 0;
}

