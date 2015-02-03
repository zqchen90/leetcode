#include <iostream>
#include <vector>
#include "czqstring.h"
#include "czqtester.h"
#include "czqvector.h"

using namespace std;

int editDistance(string word1, string word2) {
    vector<vector<int> > dp (word1.size() + 1, vector<int>(word2.size() + 1, 0));  // dp
    int index1 = 0;
    int index2 = 0;
    // Init dp, dp[i,0] = i, dp[0, j] = j
    for (int index1 = 0; index1 <= word1.size(); ++index1) {
        dp[index1][0] = index1;
    }
    for (int index2 = 0; index2 <= word2.size(); ++index2) {
        dp[0][index2] = index2;
    }

    for (index2 = 1; index2 <= word2.size(); ++index2) {
        for (index1 = 1; index1 <= word1.size(); ++index1) {
            if (word1[index1 - 1] == word2[index2 - 1]) {
                dp[index1][index2] = dp[index1 - 1][index2 - 1];
            } else {
                int min_distance = min(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                min_distance = min(min_distance, dp[index1 - 1][index2 - 1]);
                dp[index1][index2] = min_distance + 1;
            }
            /*
            if (1 == index1 && 1 == index2) {
                cout<<word1[index1 - 1]<<"  -  "<<word2[index2 - 1]<<endl;
                print_2d_vector(dp);
                cout<<"---"<<endl;
            }
            */
        }
    }
    return dp[word1.size()][word2.size()];
}

void test(string input1, string input2, int result) {
    int output = editDistance(input1, input2);
    czqassert(output, result);
}

int main() {
    test("kitten", "sitting", 3);

    return 0;
}

