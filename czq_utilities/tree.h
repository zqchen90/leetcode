#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "czqstring.h"
#include <queue>
#include <vector>
#include <stdlib.h> // atoi
#include <iostream>

const char SERIALIZE_DELIM = ',';
const std::string SERIALIZE_EMPTY = "#";

void serialized_binary_tree(TreeNode *root, std::string levelOrderTraversal) {
    using std::vector;
    using std::queue;
    using std::string;

    vector<string> elems = split(levelOrderTraversal, SERIALIZE_DELIM);
    queue<TreeNode *> q;

    if (0 == elems.size() || (0 < elems.size() && elems[0] == SERIALIZE_EMPTY)) {
        root = NULL;
        return;
    }
    
    root = new TreeNode(atoi(elems[0].c_str()));
    q.push(root);
    int level_cnt = 1;
    int level_max_node = 1;
    int level_node = 1;
    bool left_flag = true;
    TreeNode *cur = q.front();
    int i = 1;
    while (!q.empty() && i < elems.size()) {
        string e = elems[i];
        if (e != SERIALIZE_EMPTY) {
            TreeNode *p = new TreeNode(atoi(e.c_str()));
            if (left_flag) {
                cur->left = p;
                left_flag = false;
            } else {
                cur->right = p;
                q.pop();
                left_flag = true;
                cur = q.front();
            }
            q.push(p);
        } else {
            if (left_flag) {
                left_flag = false;
            } else {
                q.pop();
                left_flag = true;
                cur = q.front();
            }
        }
        i++;
    }
}

void print_tree(TreeNode *root) {
    using std::cout;
    using std::endl;
    if (NULL == root) {
        return;
    }
    cout<<"[";
    cout<<root->val;
    cout<<", ";
    if (NULL != root->left) {
        cout<<root->left->val;
    }
    cout<<", ";
    if (NULL != root->right) {
        cout<<root->right->val;
    }
    cout<<"]"<<endl;
    print_tree(root->left);
    print_tree(root->right);
}


#endif
