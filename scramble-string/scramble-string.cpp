#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    if (s1 == s2) {
        return true;
    }
    int n = s1.size();
    vector<vector<vector<bool> > > dp (n, vector<vector<bool> > (n, vector<bool> (n + 1, false)));
    // dp[i][j][k] means which s1[i,...,i+k-1] and s2[j,...,j+k-1] is scramble
    // dp[i][j][k] = any l (where to split, 1 <= l < k):
    //    Not swap:  dp[i][j][l] && dp[i + l][j + l][k - l]
    //    Swap: dp[i][j + k - l][l] && dp[i + l][j][k - l]
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                if (1 == k) {
                    dp[i][j][k] = (s1[i] == s2[j]);
                    continue;
                }
                for (int l = 1; l < k; ++l) {
                    if (dp[i][j][l] && dp[i + l][j + l][k - l] || dp[i + l][j][k - l] && dp[i][i + k - l][l]) {
                        dp[i][j][k] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][0][n];
}

void testScramble(string s1, string s2, bool result) {
    bool output = isScramble(s1, s2);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<output<<" "<<result<<endl;
    }
}

int main() {
    testScramble("great", "rgtae", true);
    testScramble("great", "rgeat", true);
    testScramble("abcde", "caebd", false);

    return 0;
}

