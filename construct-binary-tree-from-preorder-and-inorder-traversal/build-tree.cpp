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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (0 == preorder.size() && 0 == inorder.size()) {
        return NULL;
    }
    if (1 == preorder.size() && 1 == preorder.size()) {
        TreeNode *root = new TreeNode(preorder[0]);
        return root;
    }
    int root_val = preorder[0];
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), root_val);
    int root_inorder_pos = it - inorder.begin();
    int left_size = root_inorder_pos;
    int right_size = inorder.size() - root_inorder_pos - 1;

    TreeNode *root = new TreeNode(root_val);
    
    vector<int> preorder_left (preorder.begin() + 1, preorder.begin() + 1 + root_inorder_pos);
    vector<int> inorder_left(inorder.begin(), inorder.begin() + root_inorder_pos);
    TreeNode *left = buildTree(preorder_left, inorder_left);

    vector<int> preorder_right (preorder.begin() + root_inorder_pos + 1, preorder.end());
    vector<int> inorder_right(inorder.begin() + root_inorder_pos + 1, inorder.end());
    TreeNode *right = buildTree(preorder_right, inorder_right);
    
    root->left = left;
    root->right = right;
    return root;
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

