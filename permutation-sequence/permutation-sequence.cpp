#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getPermutation(int n, int k, vector<bool> &digit_used, vector<char> &digit,
                    vector<char> &path, int *curk, string &ret) {
    if (*curk >= k) {
        return;
    }
    if (path.size() == n) {
        // cout<<"find a permtutaion "<<*curk<<endl;
        *curk += 1;
        if (*curk == k) {
            // cout<<"find k"<<endl;
            for (int i = 0; i < path.size(); ++i) {
                ret.append(1, path[i]);
            }
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!digit_used[i]) {
            digit_used[i] = true;
            path.push_back(digit[i]);
            getPermutation(n, k, digit_used, digit, path, curk, ret);
            path.pop_back();
            digit_used[i] = false;
        }
    } 
    return;
}

string getPermutation(int n, int k) {
    vector<bool> digit_used (n, false);
    vector<char> digit (n, '1');
    for (int i = 1; i <= n - 1; ++i) {
        digit[i] = digit[i - 1] + 1;
    }
    string ret = "";
    vector<char> path;
    int curk = 0;
    getPermutation(n, k, digit_used, digit, path, &curk, ret);
    return ret;
}

void testGetPermutation(int n, int k, string result) {
    string output = getPermutation(n, k);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<result<<endl;
    }
}

int main() {
    testGetPermutation(3, 4, "231");
    testGetPermutation(3, 6, "321");

    return 0;
}

