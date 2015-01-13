#include <iostream>
#include <vector>
#include <string>
#include "czqvector.h"

using namespace std;

bool validNQueens(vector<int> &col_for_row, int n) {
    if (n >= col_for_row.size()) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        if (col_for_row[i] == col_for_row[n] ||
            (col_for_row[i] - col_for_row[n]) == (i - n) ||
            (col_for_row[i] - col_for_row[n]) == (n - i)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<vector<string> > &ret, vector<int> &col_for_row, int index, int n) {
    if (index == n) {
        vector<string> one_result;
        for (int i = 0; i < col_for_row.size(); ++i) {
            string row ("");
            for (int j = 0; j < n; ++j) {
                if (j == col_for_row[i]) {
                    row.append(1, 'Q');
                } else {
                    row.append(1, '.');
                }
            }
            one_result.push_back(row);
        }
        ret.push_back(one_result);
        return;
    }
    for (int i = 0; i < n; ++i) {
        col_for_row[index] = i;
        if (validNQueens(col_for_row, index)) {
            solveNQueens(ret, col_for_row, index + 1, n);            
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<int> col_for_row (n, 0);
    vector<vector<string> > ret;
    solveNQueens(ret, col_for_row, 0, n);
    return ret;
}

int main() {
    cout<<"4 Queens"<<endl;
    vector<vector<string> > ret4 = solveNQueens(4);
    print_2d_vector(ret4);
    cout<<ret4.size()<<endl;

    cout<<"8 Queens"<<endl;
    vector<vector<string> > ret8 = solveNQueens(8);
    print_2d_vector(ret8);
    cout<<ret8.size()<<endl;
    return 0;
}

