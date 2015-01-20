#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string S, string T) {
    int SLen = S.size();
    int TLen = T.size();
    vector<vector<int> > dp (SLen, vector<int> (TLen, 0));
    if (S[0] == T[0]) {
        dp[0][0] = 1;
    }
    for (int i = 1; i < SLen; ++i) {
        for (int j = 0; j <= i && j < TLen; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (S[i] == T[j]) {
                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                } else {
                    dp[i][j] += 1;
                }
            }
        }
    }
    return dp[SLen - 1][TLen - 1];
}

void test(string S, string T, int result) {
    int output = numDistinct(S, T);
    if (result == output) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<result<<endl;
    }
}

int main() {
    test("rabbbit", "rabbit", 3);    
    test("rarab", "ra", 3);
    test("rsabb", "rab", 2);
    test("rabb", "rab", 2);
    return 0;
}

