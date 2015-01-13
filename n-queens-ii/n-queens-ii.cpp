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

void solveNQueens(int &ret, vector<int> &col_for_row, int index, int n) {
    if (index == n) {
        ret += 1;
        return;
    }
    for (int i = 0; i < n; ++i) {
        col_for_row[index] = i;
        if (validNQueens(col_for_row, index)) {
            solveNQueens(ret, col_for_row, index + 1, n);            
        }
    }
}

int solveNQueens(int n) {
    vector<int> col_for_row (n, 0);
    int ret = 0;
    solveNQueens(ret, col_for_row, 0, n);
    return ret;
}

int main() {
    cout<<"4 Queens"<<endl;
    int ret4 = solveNQueens(4);
    cout<<ret4<<endl;

    cout<<"8 Queens"<<endl;
    int ret8 = solveNQueens(8);
    cout<<ret8<<endl;
    return 0;
}

