#include <iostream>
#include <vector>
#include "czqvector.h"

using namespace std;

int min_int(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int width = dungeon[0].size();
    int height = dungeon.size();
    vector<vector<int> > hp (height, vector<int> (width, 0));

    int row = height - 1;
    int col = width - 1;
    
    // fill the bottom-right
    hp[row][col] = 1;
    if (dungeon[row][col] < 0) {
        hp[row][col] -= dungeon[row][col];
    }

    // fill the bottom line
    if (width >= 2) {
    for (int c = col - 1; c >= 0; --c) {
        hp[row][c] = hp[row][c + 1] -  dungeon[row][c];
        if (hp[row][c] <= 0) {
            hp[row][c] = 1;
        }
    }
    }

    // fill the right line
    if (height >= 2) {
    for (int r = row - 1; r >= 0; --r) {
        hp[r][col] = hp[r + 1][col] - dungeon[r][col];
        if (hp[r][col] <= 0) {
            hp[r][col] = 1;
        }
    }
    }

    cout<<"fill big"<<endl;
    if (width >=2 && height >= 2) {
    // fill the remaining, no need if width < 2 || height < 2
    while (row != 0 || col != 0) {
        if (row != 0) {
            row--;
        }
        if (col != 0) {
            col--;
        }
        for (int c = col; c >= 0; --c) {
            hp[row][c] = min_int(hp[row][c + 1], hp[row + 1][c]) - dungeon[row][c];
            if (hp[row][c] <= 0) {
                hp[row][c] = 1;
            }
        }
        for (int r = row; r >= 0; --r) {
            hp[r][col] = min_int(hp[r + 1][col], hp[r][col + 1]) -  dungeon[r][col];
            if (hp[r][col] <= 0) {
                hp[r][col] = 1;
            }
        }
    }
    return hp[0][0];
}

void test(string input, char row_delim, char col_delim, int ret) {
    vector<vector<int> > dungeon = build_int_2d_vector(input, row_delim, col_delim);
    print_2d_vector(dungeon);
    int output = calculateMinimumHP(dungeon);
    if (output == ret) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<ret<<endl;
    }
}

int main() {    
    test("-2,-3,3;-5,-10,1;10,30,-5", ';', ',', 7);
    test("0", ';', ',', 1);
    test("0,0", ';', ',', 1);
    return 0;
}

