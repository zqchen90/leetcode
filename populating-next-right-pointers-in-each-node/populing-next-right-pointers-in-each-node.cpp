#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode * left, *right, *next;
};

void connect(TreeLinkNode *root) {
    queue<TreeLinkNode *> q;
                           
    if (NULL == root) {
        return;
    }
                                    
    int cur_level_cnt = 1;
    int cur_level = 0;
    int next_level_cnt = 0;
    q.push(root);
    TreeLinkNode *p;
    while (0 != q.size()) {
        p = q.front();
        q.pop();
        cur_level++;
        if (NULL != p->left) {
            q.push(p->left);
            next_level_cnt++;
        }
        if (NULL != p->right) {
            q.push(p->right);
            next_level_cnt++;
        }
        if (cur_level == cur_level_cnt) {
            p->next = NULL;
            cur_level_cnt = next_level_cnt;
            cur_level = 0;
            next_level_cnt = 0;
        } else {
            p->next = q.front();
        }
    } 
}

int main() {
    

    return 0;
}

