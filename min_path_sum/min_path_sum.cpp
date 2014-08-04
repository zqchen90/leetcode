#include <iostream>
#include <vector>

using namespace std;

enum PathFrom {
    UNKNOW,
    STARTER,
    LEFT,
    UP
};

void print_path(vector<vector<int> > &grid,
                vector<vector<int> > sum,
                vector<vector<PathFrom> > path) {
    int row = grid.size();
    int col = grid[0].size();

    vector<int> min_path;
    int cur_row = row - 1;
    int cur_col = col - 1;
    min_path.push_back(grid[cur_row][cur_col]);
    while (path[cur_row][cur_col] != STARTER) {
        if (path[cur_row][cur_col] == LEFT) {
            --cur_col;
        } else {
            --cur_row;
        }
        min_path.push_back(grid[cur_row][cur_col]);
    }
    for (int i = min_path.size() - 1; i >= 0; --i) {
        cout<<min_path[i]<<" -> ";
    }
    cout<<endl;
}

int minPathSum(vector<vector<int> > &grid) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int> > sum;
    vector<vector<PathFrom> > path;
    int i, j;
    for (i = 0; i < row; ++i) {
        vector<int> sum_row;
        vector<PathFrom> path_row;
        for (j = 0; j < col; ++j) {
            sum_row.push_back(0);
            path_row.push_back(UNKNOW);
        }
        sum.push_back(sum_row);
        path.push_back(path_row);
    }

    sum[0][0] = grid[0][0];
    path[0][0] = STARTER;

    // initialize the 1st row and 1st col
    for (i = 1; i < row; ++i) {
        sum[i][0] = sum[i - 1][0] + grid[i][0];
        path[i][0] = UP;
    }
    for (j = 1; j < col; ++j) {
        sum[0][j] = sum[0][j - 1] + grid[0][j];
        path[0][j] = LEFT;
    }

    // calculate the others
    for (i = 1; i < row; ++i) {
        for (j = 1; j < col; ++j) {
            if (sum[i - 1][j] < sum[i][j - 1]) {
                sum[i][j] = sum[i - 1][j] + grid[i][j];
                path[i][j] = UP;
            }
            else {
                sum[i][j] = sum[i][j - 1] + grid[i][j];
                path[i][j] = LEFT;
            }
        }
    }

    // print the path
    //print_path(grid, sum, path);
    return sum[row - 1][col - 1];
}

void print_grid(const vector< vector<int> > &board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main() {
    vector< vector<int> > grid;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
  
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row1.push_back(4);
    row2.push_back(5);
    row2.push_back(6);
    row2.push_back(1);
    row2.push_back(2);
    row3.push_back(1);
    row3.push_back(5);
    row3.push_back(1);
    row3.push_back(6);
    
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    
    print_grid(grid);

    cout<<minPathSum(grid)<<endl;
}