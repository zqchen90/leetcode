#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    int layer = 0;
    int max_layer = n/2 - 1;
    for (layer = 0; layer <= max_layer; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int top = matrix[first][i];
            // right -> top
            matrix[first][i] = matrix[last - i][first];
            // bottom -> right
            matrix[last - i][first] = matrix[last][last - i];
            // left -> bottom
            matrix[last][last - i] = matrix[i][last];
            // top -> left
            matrix[i][last] = top;
        }
    }
}

void print_matrix(const vector<vector<int> > &matrix) {
    cout<<"----"<<endl;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"----"<<endl;
}

void testRotate(vector<vector<int> > &matrix) {
    print_matrix(matrix);
    rotate(matrix);
    print_matrix(matrix);
}

int main() {
    vector<vector<int> > matrix;
    int arow1[] = {1,2,3};
    vector<int> row1(arow1, arow1 + 3);
    int arow2[] = {4,5,6};
    vector<int> row2(arow2, arow2 + 3);
    int arow3[] = {7,8,9};
    vector<int> row3(arow3, arow3 + 3);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    testRotate(matrix);
    return 0;
}

