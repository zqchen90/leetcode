#include <iostream>
#include "tree.h"
#include <string>

using namespace std;

int main() {
    TreeNode *root;
    serialized_binary_tree(root, "1,2,3,#,#,4,#,#,5");
    print_tree(root);
    return 0;
}

