#include <iostream>
#include <vector>
#include "czqvector.h"
#include <string>
#include <algorithm>

using namespace std;

// S[index], get the subsets with S[index+1, ...], and add S[index] in these subsets
// to get subsets with S[index, ...]
vector<vector<int> > get_subsets(vector<int> &S, int index) {
    vector<vector<int> > all_sets;
    if (index == S.size()) {
        vector<int> tmp;
        all_sets.push_back(tmp);
    } else {
        vector<vector<int> > some_sets = get_subsets(S, index + 1);
        for (int i = 0; i < some_sets.size(); ++i) {
            vector<int> set_index;
            set_index.push_back(S[index]);
            for (int j = 0; j < some_sets[i].size(); ++j) {
                set_index.push_back(some_sets[i][j]);
            }
            all_sets.push_back(some_sets[i]);
            all_sets.push_back(set_index);
        }
    }
    return all_sets;      
}

vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    return get_subsets(S, 0);
}

int main() {
    vector<int> input = build_int_vector("1,2,3", ',');
    print_vector(input);
    cout<<endl<<endl;
    vector<vector<int> > ret = subsets(input);
    print_2d_vector(ret);

    return 0;
}

