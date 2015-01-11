#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int> > ret;
                           
    if (NULL == root) {
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
            if (next_level_cnt > 0) {
                vector<int> next_level_vector;
                ret.push_back(next_level_vector);
            }
            cur_level_cnt = next_level_cnt;
            cur_level = 0;
            next_level_cnt = 0;
        }        
    }
    // Become zigzag
    bool reverse_flag = false;
    for (int i = 0; i < ret.size(); ++i) {
        if (reverse_flag) {
            reverse(ret[i].begin(), ret[i].end());
        }
        reverse_flag = !reverse_flag;
    }
    return ret;
}

void print_2d_vector(const vector<vector<int> > &mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            cout<<mat[i][j]<<",";
        }
        cout<<endl;
    }
}


int main() {
    TreeNode root(3);
    TreeNode level11(9);
    TreeNode level12(20);
    TreeNode level21(15);
    TreeNode level22(7);
    root.left = &level11;
    root.right = &level12;
    level12.left = &level21;
    level12.right = &level22;

    vector<vector<int> > ret = zigzagLevelOrder(&root);
    print_2d_vector(ret);

    return 0;
}

