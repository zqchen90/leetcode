#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeArray(int *preorder, int preorder_len, int *inorder, int inorder_len) {
    if (0 == preorder_len && 0 == inorder_len) {
        return NULL;
    }
    if (1 == preorder_len && 1 == preorder_len) {
        TreeNode *root = new TreeNode(preorder[0]);
        return root;
    }
    int root_val = preorder[0];
    int root_inorder_pos = 0;
    for (int i = 0; i < inorder_len; ++i) {
        if (inorder[i] == root_val) {
            root_inorder_pos = i;
        }
    }

    int left_size = root_inorder_pos;
    int right_size = inorder_len - root_inorder_pos - 1;

    TreeNode *root = new TreeNode(root_val);
    TreeNode *left = buildTreeArray(&preorder[1], left_size, inorder, left_size);
    TreeNode *right = buildTreeArray(&preorder[left_size + 1], right_size, &inorder[left_size + 1], right_size);
    
    root->left = left;
    root->right = right;
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    int *preorder_array = new int[n];
    int *inorder_array = new int[n];
    for (int i = 0; i < n; ++i) {
        preorder_array[i] = preorder[i];
        inorder_array[i] = inorder[i];
    }
    return buildTreeArray(preorder_array, n, inorder_array, n);
}


void printTree(TreeNode *root) {
    if (NULL == root) {
        return;
    }
    if (NULL != root->left) {
        cout<<"(left: "<<root->val<<", "<<root->left->val<<")";
    }
    if (NULL != root->right) {
        cout<<"(right: "<<root->val<<", "<<root->right->val<<")";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

void testBuildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *root = buildTree(preorder, inorder);
    printTree(root);
}
int main() {
    int preorder_array[] = {1,2,4,5,3,6};
    int inorder_array[] = {4,2,5,1,6,3};
    vector<int> preorder(preorder_array, preorder_array + 6);
    vector<int> inorder(inorder_array, inorder_array + 6);

    testBuildTree(preorder, inorder);

    return 0;
}

