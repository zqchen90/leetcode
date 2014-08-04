#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int find_next_step(int rowlen, int collen, int row, int col, int step_list[][2]) {
    for(int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            step_list[i][j] = -1;
    int step_cnt = 0;
    if (row > 0) {
        step_list[step_cnt][0] = row - 1;
        step_list[step_cnt][1] = col;
        step_cnt++;
    }

    if (col > 0) {
        step_list[step_cnt][0] = row;
        step_list[step_cnt][1] = col - 1;
        step_cnt++;
    }

    if (col < collen - 1) {
        step_list[step_cnt][0] = row;
        step_list[step_cnt][1] = col + 1;
        step_cnt++;
    }

    if (row < rowlen - 1) {
        step_list[step_cnt][0] = row + 1;
        step_list[step_cnt][1] = col;
        step_cnt++;
    }
    return step_cnt;
}
            
bool find(vector< vector<char> > &board,
        int row,
        int col,
        char **mapped, 
        const string &word, 
        const int word_index) {
    if (word_index == word.length())
        return true;

    int rowlen = board.size();
    int collen = board[0].size();
    int step_list[4][2] = {0};

    int step_cnt = find_next_step(rowlen, collen, row, col, step_list);
    if (0 == step_cnt)
        return false;
    
    for (int i = 0; i < step_cnt; ++i) {
        int next_row = step_list[i][0];
        int next_col = step_list[i][1];
        if (board[next_row][next_col] == word[word_index] &&
            0 == mapped[next_row][next_col]) {
            mapped[next_row][next_col] = 1;
            if (find(board, next_row, next_col,
                        mapped, word, word_index + 1))
                return true;
            else
                mapped[next_row][next_col] = 0;
        }
    }
    return false;
}

void print_mapped(char **mapped, int row, int col) {
    for (int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j) {
            cout<<(int)mapped[i][j]<<"\t";
        }
        cout<<endl;
    }
}

bool exist(vector< vector<char> > &board, string word) {
    int rowlen = board.size();
    int collen = board[0].size();
    
    int i, j, w;

    char **mapped = new char *[rowlen];
    
    for (i = 0; i < rowlen; ++i) {
        mapped[i] = new char [collen];
        for (j = 0; j < collen; ++j)
            mapped[i][j] = 0;
    }

    for (i = 0; i < rowlen; ++i)
        for (j = 0; j < collen; ++j)
            if (board[i][j] == word[0]) {
                mapped[i][j] = 1;
                if (find(board, i, j, mapped, word, 1)) {
                    // print_mapped(mapped, rowlen, collen);
                    
                    for (i = 0; i < rowlen; ++i) {
                        delete[] mapped[i];
                    }
                    delete[] mapped;

                    return true;
                }
                else
                    mapped[i][j] = 0;
            }
    
    // print_mapped(mapped, rowlen, collen); 
     
    for (i = 0; i < rowlen; ++i) {
        delete[] mapped[i];
    }
    delete[] mapped;

    return false;
}

void test_find_next_step() {
    int rowlen = 3;
    int collen = 4;
    int step_list[4][2] = {0};
    cout<<"======== test find_next_step ========"<<endl;
    cout<<find_next_step(rowlen, collen, 0, 0, step_list)<<" "<<2<<endl;
    cout<<find_next_step(rowlen, collen, 1, 1, step_list)<<" "<<4<<endl;
    cout<<find_next_step(rowlen, collen, 2, 1, step_list)<<" "<<3<<endl;
    cout<<find_next_step(rowlen, collen, 3, 4, step_list)<<" "<<2<<endl;
}

void print_board(const vector< vector<char> > &board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main() {
    vector< vector<char> > board;
    vector<char> row1;
    vector<char> row2;
    vector<char> row3;
  
    row1.push_back('A');
    row1.push_back('B');
    row1.push_back('C');
    row1.push_back('E');
    row2.push_back('S');
    row2.push_back('F');
    row2.push_back('C');
    row2.push_back('S');
    row3.push_back('A');
    row3.push_back('D');
    row3.push_back('E');
    row3.push_back('E');
    
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    
    print_board(board);

    // test find next step
    //test_find_next_step();
    
    string a = "SEE";
    cout<<a<<"\t1\t"<<exist(board, a)<<endl;
    a = "ABCCED";
    cout<<a<<"\t1\t"<<exist(board, a)<<endl;
    a = "ABCB";
    cout<<a<<"\t0\t"<<exist(board, a)<<endl;
    a = "ZZ";
    cout<<a<<"\t0\t"<<exist(board, a)<<endl;
    return 0;
}

