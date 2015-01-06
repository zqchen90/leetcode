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
            int offset = i - first;
            // right -> top
            matrix[first][i] = matrix[last - offset][first];
            // bottom -> right
            matrix[last - offset][first] = matrix[last][last - offset];
            // left -> bottom
            matrix[last][last - offset] = matrix[i][last];
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
    
    vector<vector<int> > matrix1;
    int arow11[] = {1,2,3,4};
    vector<int> row11(arow11, arow11 + 4);
    int arow12[] = {5,6,7,8};
    vector<int> row12(arow12, arow12 + 4);
    int arow13[] = {9,10,11,12};
    vector<int> row13(arow13, arow13 + 4);
    int arow14[] = {13,14,15,16};
    vector<int> row14(arow14, arow14 + 4);
    matrix1.push_back(row11);
    matrix1.push_back(row12);
    matrix1.push_back(row13);
    matrix1.push_back(row14);
    testRotate(matrix1);
    return 0;
}

