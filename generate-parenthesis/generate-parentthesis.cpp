#include <iostream>
#include <string>
#include <vector>
#include "czqvector.h"

using namespace std;

void add_parenthesis(int left, int right, string &path, vector<string> &ret) {
    if (left < 0 || right < left) {
        return;
    }
    if (0 == left && 0 == right) {
        ret.push_back(path);
    }
    // Alway append a left parenthesis first
    if (left > 0) {
        path.append(1, '(');
        add_parenthesis(left - 1, right, path, ret);
        path.erase(path.length()-1, 1);
    }
    // Apeend right parenthsis only if there are more left than right
    if (right > left) {
        path.append(1, ')');
        add_parenthesis(left, right - 1, path, ret);
        path.erase(path.length()-1, 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    string path = "";
    add_parenthesis(n, n, path, ret);
    return ret;
}

int main() {
    vector<string> ret3 = generateParenthesis(3);
    print_vector(ret3);
    cout<<endl;
    vector<string> ret2 = generateParenthesis(2);
    print_vector(ret2);
    cout<<endl;
    return 0;
}

