#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
    int ret = 0;
    int runner = 1;
    while (runner < n) {
        if (A[ret] == A[runner]) {
            runner++;
        } else {
            ret++;
            A[ret] = A[runner];
            runner++;
        }
    }
    return ret + 1;
}

void testRemoveDuplicates(int input[], int n, int result[], int n_result) {
    int n_output = removeDuplicates(input, n);
    if (n_output != n_result) {
        cout<<"Length Fail "<<n_output<<" "<<n_result<<endl;
    } else {
        bool testFail = false;
        for (int i = 0; i < n_result; i++) {
            if (input[i] != result[i]) {
                testFail = true;
                break;
            }
        }
        if (testFail) {
            cout<<"Element Fail ";
            cout<<endl;
        } else {
            cout<<"Pass"<<endl;
        }
    }
}

int main() {
    int input[] = {1,1,2};
    int result[] = {1,2};
    testRemoveDuplicates(input, 3, result, 2);

    return 0;
}

