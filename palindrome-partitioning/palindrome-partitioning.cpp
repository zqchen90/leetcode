#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string &str, int s, int e) {
    while (s < e) {
        if (str.at(s) != str.at(e)) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

vector<vector<string> > partition(string s, int start) {
    vector<vector<string> > ret;
    int i;
    int n = s.length();
    for (i = start; i < n; ++i) {
        if (isPalindrome(s, start, i)) {
            if (i + 1 < n) {
                vector<vector<string> > result2 = partition(s, i + 1);
                for (int k = 0; k < result2.size(); ++k) {
                    ret.push_back(vector<string> (result2[k].size() + 1, ""));
                    ret.back()[0] = s.substr(start, i - start + 1);
                    copy(result2[k].begin(), result2[k].end(), ret.back().begin() + 1);
                }
            } else {
                ret.push_back(vector<string> (1, s.substr(start, i - start + 1)));
            }
        }
    }    
    return ret;
}

vector<vector<string> > partition(string s) {
    return partition(s, 0);
}

void print_vector_string(vector<vector<string> > s) {
    cout<<"print"<<endl;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    print_vector_string(partition("aab")); 

    return 0;
}

