#include <iostream>
#include "tree.h"
#include <string>

using namespace std;

int main() {
    TreeNode *root = serialized_binary_tree( "1,2,3,#,#,4,#,#,5");
    cout<<"build tree done."<<endl;
    if (NULL == root) cout<<"root is null"<<endl;
    print_tree(root);
    return 0;
}

