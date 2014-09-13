#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <string.h>

using namespace std;

int evalRPN(vector<string> &tokens) {
    if (0 == tokens.size()) {
        return 0;
    }
    stack<int> wait;
    int num1 = 0;
    int num2 = 0;
    vector<string>::iterator iter;
    for (iter = tokens.begin(); iter != tokens.end(); ++iter) {
        if (*iter == "+") {
            num1 = wait.top();
            wait.pop();
            num2 = wait.top();
            wait.pop();
            wait.push(num1 + num2);
            continue;
        }
        if (*iter == "-") {
            num1 = wait.top();
            wait.pop();
            num2 = wait.top();
            wait.pop();
            wait.push(num2 - num1);
            continue;
        }
        if (*iter == "*") {
            num1 = wait.top();
            wait.pop();
            num2 = wait.top();
            wait.pop();
            wait.push(num1 * num2);
            continue;
        }
        if (*iter == "/") {
            num1 = wait.top();
            wait.pop();
            num2 = wait.top();
            wait.pop();
            wait.push(num2 / num1);
            continue;
        }
        wait.push(atoi(iter->c_str()));
    }
    return wait.top();
}

int main() {
    string test1[] = {"2", "1", "+", "3", "*"};
    int ans1 = 9;
    vector<string> tokens1(test1, test1 + sizeof(test1) / sizeof(string));
    int ret1 = evalRPN(tokens1);
    if (ret1 == ans1) {
        cout<<"test1 success"<<endl;
    } else {
        cout<<"test1 fail, expect: "<<ans1<<", output: "<<ret1<<endl;
    }
    string test2[] = {"4", "13", "5", "/", "+"};
    int ans2 = 6;
    vector<string> tokens2(test2, test2 + sizeof(test2) / sizeof(string));
    int ret2 = evalRPN(tokens2);
    if (ret2 == ans2) {
        cout<<"test2 success"<<endl;
    } else {
        cout<<"test2 fail, expect: "<<ans2<<", output: "<<ret2<<endl;
    }


    return 0;
}

