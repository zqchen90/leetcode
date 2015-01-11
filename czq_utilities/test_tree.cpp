#include <iostream>
#include "tree.h"
#include <string>

using namespace std;

int main() {
    TreeNode *root = build_binary_tree( "1,2,3,#,#,4,#,#,5");
    cout<<"Tree 1"<<endl;
    print_tree(root);
    
    TreeNode *root2 = build_binary_tree( "1,2,3,#,#,4,#,#,5");
    cout<<"Tree 2"<<endl;
    print_tree(root2);
    
    cout<<"Two trees equal? "<<tree_equal(root, root2)<<endl;

    return 0;
}

