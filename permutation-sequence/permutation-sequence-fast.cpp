#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getPermutation(int n, int k, vector<bool> &digit_used, vector<char> &digit,
                    vector<char> &path, vector<int> &factor, string &ret) {
    if (n == 0) {
        for (int i = 0; i < path.size(); ++i) {
            ret.append(1, path[i]);
        }
        return;
    }
    int first_digit = (k - 1) / factor[n-1];
    k -= factor[n-1] * first_digit;
    //cout<<"first: "<<first_digit<<" k: "<<k<<endl;
    int not_used_cnt = 0;
    for (int i = 0; i < 9; i++) {
        if (!digit_used[i]) {
            not_used_cnt++;
            if (not_used_cnt == first_digit + 1) {
                path.push_back(digit[i]);
                digit_used[i] = true;
            }
        }
    }
    getPermutation(n-1, k, digit_used, digit, path, factor, ret);
    return;
}


string getPermutation(int n, int k) {
    vector<bool> digit_used (n, false);
    vector<char> digit (n, '1');
    vector<int> factor (n + 1, 1); // n!
    for (int i = 1; i <= n - 1; ++i) {
        digit[i] = digit[i - 1] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        factor[i] = factor[i - 1] * i;
    }
    string ret = "";
    vector<char> path;
    getPermutation(n, k, digit_used, digit, path, factor, ret);
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

