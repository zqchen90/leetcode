#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int> > ret;
                           
    if (NULL == root) {
        vector<int> tmp;
        ret.push_back(tmp);
        return ret;
    }
                                    
    int cur_level_cnt = 1;
    int cur_level = 0;
    int next_level_cnt = 0;
    q.push(root);
    TreeNode *p;
    vector<int> first_level;
    ret.push_back(first_level);
    while (0 != q.size()) {
        p = q.front();
        q.pop();
        cur_level++;
        ret[ret.size() - 1].push_back(p->val);
        if (NULL != p->left) {
            q.push(p->left);
            next_level_cnt++;
        }
        if (NULL != p->right) {
            q.push(p->right);
            next_level_cnt++;
        }
        if (cur_level == cur_level_cnt) {
            vector<int> next_level_vector;
            ret.push_back(next_level_vector);
            cur_level_cnt = next_level_cnt;
            cur_level = 0;
        }        
    }
    return ret;
}

int main() {
    

    return 0;
}

